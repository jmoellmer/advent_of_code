#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "../ParseFile.h"

class Puzzle {
    vector<int> cols{};
    vector<queue<char>> cratesq;
    vector<stack<char>> crates;

public:
    Puzzle(string input) {
        int sum = 0;

        // initialize cols
        for (int i = 1; i < 34; i += 4)
            cols.push_back(i);
        for (int i = 0; i < 9; i++) {
            cratesq.push_back(queue<char>{});
            crates.push_back(stack<char>{});
        }

        // part 1
        if (!parse_file(input, 1, [&](const vector<string> &lines) -> bool {
            string line = lines[0];
            if (line.find("move") == 0) {
                cout << "processing line: " << line << endl;
                return true;
            } else {
                int n_cols = cols.size();
                char crate = line[cols[0]];
                if (crate != '1') {
                    for (int i = 0; i < n_cols; i++) {
                        crate = line[cols[i]];
                        if (crate != ' ') {
                            cratesq[i].push(crate);
                        }
                    }
                } else if (crate == '1') {
                    for (int i = 0; i < n_cols; i++) {
                        while (!cratesq[i].empty()) {
                            crates[i].push(cratesq[i].front());
                            cratesq[i].pop();
                        }
                    }
                }
            }
            return true;
        })) {
            cout << "Some error in the input file." << endl;
        }

        cout << "done." << endl;
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
