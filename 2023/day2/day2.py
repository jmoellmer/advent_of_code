import re

c = {
    'r': 12,
    'g': 13,
    'b': 14
}

gr = []
gg = []
gb = []

gok = []

def load(filename):
    with open(filename) as f:
        return f.readlines()
    

def cube_color_idxs(line):
    reds = [m.start(0) for m in re.finditer('red', line)]
    greens = [m.start(0) for m in re.finditer('green', line)]
    blues = [m.start(0) for m in re.finditer('blue', line)]
    return reds, greens, blues


def cube_count(idx, line):    
    i = idx-2
    ch = line[i]
    while ch != ' ':
        i = i - 1
        ch = line[i]
    return int(line[i+1:idx-1])
    

def pass_colors(line, reds, greens, blues):
    
    for idx in reds:
        n = cube_count(idx, line)
        if n > c['r']:
            return False

    for idx in greens:
        n = cube_count(idx, line)
        if n > c['g']:
            return False

    for idx in blues:
        n = cube_count(idx, line)
        if n > c['b']:
            return False
        
    return True


def main():
    lines = load('2023/day2/data.txt')

    valid_games = []
    for (i, game) in enumerate(lines):
        r, g, b = cube_color_idxs(game)
        if (pass_colors(game, r, g, b)):
            valid_games.append(i + 1)
    print(f"Valid Games: {sum(valid_games)}")


if __name__ == '__main__':
    main()