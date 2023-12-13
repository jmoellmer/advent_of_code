import re

c = {
    'r': 12,
    'g': 13,
    'b': 14
}


def load(filename):
    with open(filename) as f:
        return f.readlines()
  

def split_line(line):
    game_n, game = line.split(':')    
    game_n = int(re.findall('\d+', game_n)[0])
    return game_n, game


def decode_game(game):
    colors = [game[m.start(0)] for m in re.finditer('red|green|blue', game)]
    n = [int(n) for n in re.findall(r'\d+', game)]
    if len(colors) != len(n): raise ValueError("colors and n different lengths")
    return n, colors


def max_cubes(colors, n, c):
    max_c = -1

    for (idx, _) in enumerate(colors):
        if colors[idx] == c:
            max_c = max(max_c, n[idx])

    return max_c

def main():
    lines = load('advent_of_code/2023/day2/data.txt')

    # part 1
    valid_games = []
    for line in lines:
        game_n, game = split_line(line)
        n, colors = decode_game(game)
        max_n = max(n)
        max_idx = n.index(max_n)
        
        if max_n < c[colors[max_idx]]:
            valid_games.append(game_n)

    print(f"Part 1: {sum(valid_games)}")

    # part 2
    power_sets = []
    for line in lines:
        game_n, game = split_line(line)
        n, colors = decode_game(game)
        
        max_r = max_cubes(colors, n, 'r')
        max_g = max_cubes(colors, n, 'g')
        max_b = max_cubes(colors, n, 'b')

        power_sets.append(max_r * max_g * max_b)

    print(f"Part 2: {sum(power_sets)}")

if __name__ == '__main__':
    main()
