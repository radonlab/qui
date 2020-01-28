import os
import json
import shutil
import tempfile
from urllib import request


class DepInfo:
    def __init__(self, d):
        self.name = d['name']
        self.type = d['type']
        self.version = d['version']
        self.url = d['url']


def find_project_root(lookup_file='.git'):
    p = os.path.dirname(os.path.abspath(__file__))
    while not os.path.exists(os.path.join(p, lookup_file)):
        if p == os.path.dirname(p):
            raise Exception('Failed to find "{}"'.format(lookup_file))
        p = os.path.dirname(p)
    return p


def download_from_url(url, target_file):
    with request.urlopen(url) as resp:
        with open(target_file, 'wb') as fp:
            shutil.copyfileobj(resp, fp)


def download_and_extract_zip(dep, target_dir):
    url = dep.url.format(version=dep.version)
    tmp = tempfile.mktemp()
    download_from_url(url, tmp)


def download_dependencies(dep_list, dest_dir):
    for dep in dep_list:
        target_dir = os.path.join(dest_dir, dep.name)
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
