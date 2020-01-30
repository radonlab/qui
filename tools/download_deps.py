import os
import json
import shutil
import hashlib
import tempfile
import tarfile
from urllib import request
from term import Progress


class DepInfo:
    def __init__(self, d):
        self.name = d['name']
        self.type = d['type']
        self.url = d['url']
        self.checksum = d.get('checksum')


def find_project_root(lookup_file='.git'):
    p = os.path.dirname(os.path.abspath(__file__))
    while not os.path.exists(os.path.join(p, lookup_file)):
        if p == os.path.dirname(p):
            raise Exception('Failed to find "{}"'.format(lookup_file))
        p = os.path.dirname(p)
    return p


def clean_target_dir(target):
    if os.path.exists(target):
        shutil.rmtree(target)


def download_from_url(url, target, label='Download'):
    prog = Progress(label)
    with request.urlopen(url) as res, open(target, 'wb') as fp:
        total_size = int(res.getheader('Content-Length'))
        count_size = 0
        buf_size = 4096
        while True:
            buf = res.read(buf_size)
            if not buf:
                break
            fp.write(buf)
            count_size += len(buf)
            prog.update(count_size / total_size)


def extract_zip_file(file, target):
    with tarfile.open(file) as arch:
        arch.extractall(target)


def verify_checksum(file, checksum):
    md5 = hashlib.md5()
    with open(file, 'rb') as fp:
        buf_size = 4096
        while True:
            buf = fp.read(buf_size)
            if not buf:
                break
            md5.update(buf)
    digest = md5.hexdigest()
    if digest != checksum:
        raise Exception('Mismatched checksum')


def download_and_extract_zip(dep, target_dir):
    tmp = tempfile.mktemp()
    label = 'Download: {}'.format(dep.name)
    download_from_url(dep.url, tmp, label)
    if dep.checksum:
        verify_checksum(tmp, dep.checksum)
    extract_zip_file(tmp, target_dir)


def download_dependencies(dep_list, dest_dir):
    for dep in dep_list:
        target_dir = os.path.join(dest_dir, dep.name)
        clean_target_dir(target_dir)
        if dep.type == 'zip':
            download_and_extract_zip(dep, target_dir)
        else:
            raise Exception('Unsupported type')


def main():
    root_dir = find_project_root()
    dest_dir = os.path.join(root_dir, 'third_party')
    deps_file = os.path.join(root_dir, 'third_party', 'deps.json')
    with open(deps_file, 'r') as fp:
        dep_list = map(DepInfo, json.load(fp))
    download_dependencies(dep_list, dest_dir)


if __name__ == '__main__':
    main()
