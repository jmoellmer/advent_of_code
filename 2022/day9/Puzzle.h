#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../ParseFile.h"

class Puzzle {
private:

public:
    Puzzle(string input) {
        if (!parse_file(input, 1,
                        [&](const vector<string> &lines) {
                            return true;
                        }
        )) {
            cout << "Some error with the input file." << endl;
        }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
