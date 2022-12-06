#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <string>
#include <sstream>
#include "ParseFile.h"
// 2-8,3-7
// 3-7,2-8
// 2,3,7,8
class Puzzle {
public:
    Puzzle(string input) {
        int sum = 0;
        if (!parse_file(input, 1, [&](const vector<string>& lines) -> bool {
            auto sections = split(lines[0]);
            int a0 = sections[0], b0 = sections[1];
            int a1 = sections[2], b1 = sections[3];

            sort(begin(sections), end(sections));

            if (a0 == sections[0] && b0 == sections[3] ||
                a1 == sections[0] && b1 == sections[3])
                sum++;

            return true;
        }))
        {
            cout << "Some error in the input file." << endl;
        }
        cout << "overlapping pairs: " << sum << endl;
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
