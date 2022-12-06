#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <string>
#include <sstream>
#include <set>
#include "ParseFile.h"

class Puzzle {
private:
    bool overlap(const vector<int>& sections, int a0, int b0, int a1, int b1) {
        if (a0 == sections[0] && b0 == sections[3] ||
            a1 == sections[0] && b1 == sections[3])
            return true;
    }

public:
    Puzzle(string input) {
        int sum = 0;
        // part 1
        if (!parse_file(input, 1, [&](const vector<string>& lines) -> bool {
            auto sections = split(lines[0]);
            int a0 = sections[0], b0 = sections[1];
            int a1 = sections[2], b1 = sections[3];

            sort(begin(sections), end(sections));

            if (overlap(sections, a0, b0, a1, b1))
                sum++;

            return true;
        })) {
            cout << "Some error in the input file." << endl;
        }
        cout << "fully overlapping pairs: " << sum << endl;

        // part2
        sum = 0;
        if (!parse_file(input, 1, [&](const vector<string>& lines) -> bool {
            auto sections = split(lines[0]);
            int a0 = sections[0], b0 = sections[1];
            int a1 = sections[2], b1 = sections[3];

            sort(begin(sections), end(sections));

            if (overlap(sections, a0, b0, a1, b1))
                sum++;
            else if ( !(b0 < a1 || a0 > b1) )
                sum++;

            return true;
        })) {

        }
        cout << "ranges overlapped pairs: " << sum << endl;

    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
