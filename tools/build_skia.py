import os
import subprocess


def build():
    os.chdir('../third_party/skia')
    subprocess.call(['bin/gn', 'gen', 'out/Shared', '--args=is_official_build=true is_component_build=true'])
    subprocess.call(['ninja', '-C', 'out/Shared'])


if __name__ == '__main__':
    build()
