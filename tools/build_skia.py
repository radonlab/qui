import os
import subprocess
from buildutils import find_project_root


def build():
    root_dir = find_project_root()
    skia_dir = os.path.join(root_dir, 'third_party', 'skia')
    os.chdir(skia_dir)
    subprocess.call(['bin/gn', 'gen', 'out/Shared', '--args=is_official_build=true is_component_build=true'])
    subprocess.call(['ninja', '-C', 'out/Shared'])


if __name__ == '__main__':
    build()
