#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <string>
#include <sstream>
#include <set>
#include "ParseFile.h"

class Puzzle {

public:
    Puzzle(string input) {
        int sum = 0;

        // part 1
        if (!parse_file(input, 1, [&](const vector<string>& lines) -> bool {

            return true;
        })) {
            cout << "Some error in the input file." << endl;
        }
        cout << "fully overlapping pairs: " << sum << endl;

    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
