import os
import json
import shutil
import subprocess


class DepInfo:
    def __init__(self, d):
        self.name = d['name']
        self.type = d['type']
        self.url = d['url']
        self.branch = d.get('branch')

    def download_to(self, target_dir):
        assert(self.type == 'git')
        subprocess.call(['git', 'clone', self.url, target_dir])

    def checkout(self):
        subprocess.call(['git', 'checkout', self.branch])


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
    os.makedirs(target)


def download_dependencies(dep_list, dest_dir):
    for dep in dep_list:
        target_dir = os.path.join(dest_dir, dep.name)
        clean_target_dir(target_dir)
        dep.download_to(target_dir)


def checkout_branches(dep_list):
    for dep in dep_list:
        dep.checkout()


def main():
    root_dir = find_project_root()
    dest_dir = os.path.join(root_dir, 'third_party')
    deps_file = os.path.join(root_dir, 'third_party', 'deps.json')
    with open(deps_file, 'r') as fp:
        dep_list = map(DepInfo, json.load(fp))
    download_dependencies(dep_list, dest_dir)
    checkout_branches(dep_list)


if __name__ == '__main__':
    main()
