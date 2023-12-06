import os
import re
import unittest
import day2

class Day2(unittest.TestCase):
    """Tests for AOC day2"""

    def setUp(self):
        self.filename = "2023/day2/data.txt"
        with open(self.filename, 'w') as f:
            lines = [
                "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n",
                "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n",
                "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n",
                "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n",
                "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"]

            f.writelines(lines)

    def tearDown(self):
        try:
            os.remove(self.filename)
        except OSError:
            pass
    
    def test_pass(self):
        lines = day2.load(self.filename)        
        reds, greens, blues = day2.cube_color_idxs(lines[0])
        self.assertEqual(day2.pass_colors(lines[0], reds, greens, blues), True)
         
    def test_fails(self):
        lines = day2.load(self.filename)        
        reds, greens, blues = day2.cube_color_idxs(lines[2])
        self.assertEqual(day2.pass_colors(lines[2], reds, greens, blues), False)

    def test_default_case(self):
        lines = day2.load(self.filename)

        valid_games = []
        for (i, game) in enumerate(lines):
            r, g, b = day2.cube_color_idxs(game)
            if (day2.pass_colors(game, r, g, b)):
                valid_games.append(i + 1)
        self.assertEqual(sum(valid_games), 8)



if __name__ == '__main__':
    unittest.main()

