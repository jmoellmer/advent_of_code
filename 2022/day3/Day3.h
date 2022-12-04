#ifndef ADVENT_OF_CODE_2022_DAY2_H
#define ADVENT_OF_CODE_2022_DAY2_H

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;

#include "ParseFile.h"

class Day3 {
private:
    string input;
    map<char, int> mmap0;
    map<char, int> mmap1;
    map<char, int> letter_map;
    int sum{0};

public:
    Day3(string input) : input(input) {
        for (int i = 1;  i <= 26; ++i) {
            char letter = 'a' + i - 1;
            letter_map[letter] = i;
        }

        if (!parse_file(input,
                        [&](const string& line) -> bool {
                            if (!line.empty()) {
                                mmap0.clear();
                                mmap1.clear();
                                int n = line.size();
                                int m = (n / 2);

                                for (int i = 0; i < m; ++i) {
                                    char ch = line[i];
                                    mmap0.insert(pair{ch, priority(ch)});
                                }

                                for (int i = m; i < n; ++i) {
                                    char ch = line[i];
                                    mmap1.insert(pair{ch, priority(ch)});
                                }

                                map<char, int> union_map;
                                set_intersection(begin(mmap0), end(mmap0),
                                                 begin(mmap1), end(mmap1),
                                                 inserter(union_map, begin(union_map)));

                                for (const auto& [k, v] : union_map) {
                                    //cout << "[" << k << "," << v << "], ";
                                    sum += v;
                                }
                            }
                            return true;
                        }))
        {
            cout << "Some error parsing the input file." << endl;
        }
        cout << "priority sum = " << sum << endl;
    }

    int priority(char item) {
        int priority = letter_map[tolower(item)];
        if (isupper(item))
            priority += 26;
        return priority;
    }

};

#endif //ADVENT_OF_CODE_2022_DAY2_H
