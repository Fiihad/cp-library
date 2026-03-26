import sys
import re

MAX_LEN = 42

def is_preprocessor(line):
    return line.startswith('#')

def is_comment(line):
    return line.startswith('//') or line.startswith('/*')

def safe_to_merge(prev, cur):
    if not prev or not cur:
        return False
    if is_preprocessor(prev) or is_preprocessor(cur):
        return False
    if is_comment(cur):
        return False
    if cur.startswith('}'):
        return False
    return True

def normalize_spaces(line):
    patterns = [
        r'\s*,\s*',
        r'\s*=\s*',
        r'\s*\+\s*',
        r'\s*-\s*',
        r'\s*\*\s*',
        r'\s*/\s*',
        r'\s*<\s*',
        r'\s*>\s*'
    ]
    for p in patterns:
        line = re.sub(p, lambda m: m.group(0).strip(), line)
    return line

def compress(lines):
    out = []
    buf = None

    for raw in lines:
        # remove leading/trailing spaces and tabs
        line = raw.replace('\t', '').strip()

        # preserve blank lines exactly
        if line == "":
            if buf is not None:
                out.append(buf)
                buf = None
            out.append("")  # keep empty line
            continue

        line = normalize_spaces(line)

        if buf is None:
            buf = line
            continue

        if (
            safe_to_merge(buf, line)
            and len(buf) + 1 + len(line) < MAX_LEN
        ):
            buf += " " + line
        else:
            out.append(buf)
            buf = line

    if buf is not None:
        out.append(buf)

    return out

if __name__ == "__main__":
    lines = sys.stdin.readlines()
    result = compress(lines)
    for l in result:
        print(l)
