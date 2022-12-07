#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "../ParseFile.h"

class Puzzle {
    vector<int> cols{};
    vector<string> header;
    vector<stack<char>> stacks;

public:
    Puzzle(string input) {
        int sum = 0;

        // initialize cols
        int n_cols = 9;
        int n = (n_cols * 4) - 2;
        for (int i = 1; i < n; i += 4)
            cols.push_back(i);
        for (int i = 0; i < n_cols; i++)
            stacks.push_back(stack<char>{});

        // part 1
        if (!parse_file(input, 1, [&](const vector<string> &lines) -> bool {
            string line = lines[0];
            if (line.find("#") == 0)
                return true;
            else if (line.find("move") == 0) {
                vector<string> tokens;
                stringstream ss(line);
                for (string token; getline(ss, token, ' ');)
                    tokens.push_back(token);

                int move = stoi(tokens[1]);
                int from = stoi(tokens[3]) - 1;
                int to = stoi(tokens[5]) - 1;

                cout << "move " << move << " from " << from + 1 << " to " << to + 1 << endl;
                vector<char> crates;
                int m = move;
                while (m > 0) {
                    char crate = stacks[from].top();
                    stacks[from].pop();
                    crates.push_back(crate);
                    m--;
                }
                m = move;
                while (m > 0) {
                    stacks[to].push(crates[m-1]);
                    m--;
                }


                return true;
            } else {
                char crate = line[cols[0]];
                if (crate != '1') {
                    header.push_back(line);
                } else if (crate == '1') {
                    int n_lines = header.size();
                    int n_cols = cols.size();
                    for (int l = n_lines - 1; l >= 0; --l)
                        for (int s = 0; s < n_cols; ++s) {
                            crate = header[l][cols[s]];
                            if (crate != ' ' && crate != '\0')
                                stacks[s].push(crate);
                        }
                }
            }
            return true;
        })) {
            cout << "Some error in the input file." << endl;
        }

        for (const auto& s : stacks) {
            if (s.size() > 0)
                cout << s.top();
        }
        cout << "\ndone." << endl;
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
