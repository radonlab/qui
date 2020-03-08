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


def download_dependencies(dep_list, dest_dir):
    for dep in dep_list:
        target_dir = os.path.join(dest_dir, dep.name)
        clean_target_dir(target_dir)


def main():
    root_dir = find_project_root()
    dest_dir = os.path.join(root_dir, 'third_party')
    deps_file = os.path.join(root_dir, 'third_party', 'deps.json')
    with open(deps_file, 'r') as fp:
        dep_list = map(DepInfo, json.load(fp))
    download_dependencies(dep_list, dest_dir)


if __name__ == '__main__':
    main()
