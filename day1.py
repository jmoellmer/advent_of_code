# day1.py

import re

digits = {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9
}

def decode(line):
    v = re.findall(r'\d', line)
    if not v:
        return 0
    return int(v[0] + v[-1])


def decode1(line):
    v = re.findall(r'\d', line)
    if not v:
        return 0
    return v[0]


def decode2(line):
    v = re.findall(r'\d', line)
    if not v:
        return 0
    return v[-1]


def reverse_decode(line):
    v2 = 0
    n = -1
    while v2 == 0:
        n = n - 1        
        v2 = decode2(re.sub('|'.join(digits.keys()), lambda m: str(digits[m.group(0)]), line[n:len(line)]))
    return v2


def fwd_rev_decode(line):
    v1 = decode1(re.sub('|'.join(digits.keys()), lambda m: str(digits[m.group(0)]), line))
    v2 = reverse_decode(line)
    return int(v1 + v2)


def main():
    # Part 1
    with open('2023/day1/data.txt', 'r') as f:
        cv = 0
        for line in f:
            n = decode(line)
            cv += n
        print(f"Part 1: Sum of calibration values: {cv}\n")

    # Part 2
    with open('2023/day1/data.txt', 'r') as f:        
        cv = 0
        for line in f:
            n = fwd_rev_decode(line)
            cv += n
        print(f"Part 2: Sum of calibration values: {cv}\n")

if __name__ == '__main__':
    main()
