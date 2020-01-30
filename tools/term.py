import re
import io
import math
import shutil


class _Segment:
    def __init__(self, text, align, width):
        self.text = text
        self.align = align
        self.width = width

    def to_string(self, getvalue):
        if not self.text.startswith('$'):
            return self.text
        # placeholder
        value = getvalue(self.text[1:], self.width)
        if self.align == 'r':
            value = value.rjust(self.width)
        else:
            value = value.ljust(self.width)
        return value[:self.width]


class Progress:
    def __init__(self, label='', ratio=0):
        self.label = label
        self.ratio = ratio
        self.config()

    def config(self, template='$label:20 [$progress] $percent:20'):
        size = shutil.get_terminal_size()
        self.max_width = size[0]
        self.max_height = size[1]
        self.segs = self._parse(template)

    @property
    def percent(self):
        value = math.floor(self.ratio * 100)
        return '{}%'.format(value)

    def _parse(self, template):
        pat = re.compile(r'(\$\w+)(?:\:(l|r)?(\d+))?')
        segs = []
        last = 0
        for m in pat.finditer(template):
            text = template[last:m.start()]
            if text:
                segs.append(_Segment(text, None, len(text)))
            last = m.end()
            text = m.group(1)
            align = m.group(2)
            width = int(m.group(3)) if m.group(3) else 0
            segs.append(_Segment(text, align, width))
        # calculate auto width
        rest_width = self.max_width - sum(map(lambda s: s.width, segs))
        auto_count = sum(map(lambda s: 1 if s.width == 0 else 0, segs))
        auto_width = rest_width // auto_count
        for s in segs:
            if s.width == 0:
                s.width = auto_width
        return segs

    def _get_value(self, name, width):
        if name == 'progress':
            value = '=' * math.floor(self.ratio * width)
        else:
            value = getattr(self, name, '')
        return str(value)

    def redraw(self):
        line = io.StringIO()
        for s in self.segs:
            line.write(s.to_string(self._get_value))
        end = '\r' if self.ratio < 1 else '\n'
        print(line.getvalue(), end=end, flush=True)

    def update(self, ratio=0):
        self.ratio = ratio
        self.redraw()
