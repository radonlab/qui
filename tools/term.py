import re
import math
import shutil


class _StringSeg:
    def __init__(self, name, text, width):
        self.name = name
        self.text = text
        self.width = width

    def __str__(self):
        return self.text.ljust(self.width)[:self.width]


class Progress:
    def __init__(self, name, rate=0, total=100):
        self.name = name
        self.rate = rate
        self.total = total
        self.config()

    def config(self, template='$name:16 [$progress] $percentage:10'):
        size = shutil.get_terminal_size()
        self.max_width = size[0]
        self.max_height = size[1]
        self.segs = self._parse(template)

    def _parse(self, template):
        pat = re.compile(r'\$(\w+)(?:\:(\d+))?')
        segs = []
        last = 0
        for m in pat.finditer(template):
            text = template[last:m.start()]
            if text:
                segs.append(_StringSeg(None, text, len(text)))
            last = m.end()
            name = m.group(1)
            width = int(m.group(2)) if m.group(2) else 0
            segs.append(_StringSeg(name, None, width))
        # calculate auto width
        rest_width = self.max_width - sum(map(lambda s: s.width, segs))
        auto_count = sum(map(lambda s: 1 if s.width == 0 else 0, segs))
        auto_width = rest_width // auto_count
        for s in segs:
            if s.width == 0:
                s.width = auto_width
        return segs

    def redraw(self):
        current = math.floor(self.total * self.rate)
        ctx = {
            'name': self.name,
            'progress': '=',
            'percentage': '{}/{}'.format(current, self.total),
        }
        for s in self.segs:
            if s.name is not None:
                s.text = ctx.get(s.name)
                if s.name == 'progress':
                    s.text = s.text[0] * math.floor(s.width * self.rate)
        line = ''.join(map(str, self.segs))
        end = '\r' if self.rate < 1 else '\n'
        print(line, end=end, flush=True)

    def update(self, rate):
        self.rate = rate
        self.redraw()
