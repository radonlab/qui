import os
import subprocess
from buildutils import find_project_root


build_args = {
    'is_official_build': True,
    'is_component_build': True,
}


def stringify_args(args):
    pairs = []
    for key, val in args.items():
        sval = ''
        if type(val) is bool:
            sval = 'true' if val else 'false'
        else:
            sval = str(val)
        pairs.append('{}={}'.format(key, sval))
    return ' '.join(pairs)


def build():
    root_dir = find_project_root()
    skia_dir = os.path.join(root_dir, 'third_party', 'skia')
    os.chdir(skia_dir)
    args = stringify_args(build_args)
    subprocess.call(['bin/gn', 'gen', 'out/Shared', '--args={}'.format(args)])
    subprocess.call(['ninja', '-C', 'out/Shared'])


if __name__ == '__main__':
    build()
