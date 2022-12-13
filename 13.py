#!/usr/bin/env python3
import sys
from itertools import zip_longest
from functools import cmp_to_key

def inord(x, y):
    if isinstance(x, int) and isinstance(y, int):
        return (x > y) - (x < y)

    if isinstance(x, list) and isinstance(y, list):
        for a, b in zip_longest(x, y):
            if a is None:
                return -1
            elif b is None:
                return 1
            z = inord(a, b)
            if z != 0:
                return z
        else:
            return 0

    if isinstance(x, int) and isinstance(y, list):
        return inord([x], y)

    if isinstance(x, list) and isinstance(y, int):
        return inord(x, [y])


data = [eval(l) for l in open(sys.argv[1]) if l != "\n"]
cnt = 0

for i in range(0, len(data)//2):
    if inord(data[i*2], data[i*2+1]) < 0:
        cnt+=(i +1)

data.extend([[[2]],[[6]]])
data.sort(key=cmp_to_key(inord))

f = data.index([[2]]) + 1
s = data.index([[6]]) + 1
print(f*s)
