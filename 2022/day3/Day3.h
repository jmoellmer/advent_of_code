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
    map<char, int> m0;
    map<char, int> m1;
    map<char, int> letter_map;
    int sum{0};

public:
    Day3(string input) : input(input) {
        for (int i = 1;  i <= 26; ++i) {
            char letter = 'a' + i - 1;
            letter_map[letter] = i;
        }

        // problem 1
        if (!parse_file(input, 1, [&](const vector<string>& string_list) -> bool {
                            string line = string_list[0];
                            if (!line.empty()) {
                                m0.clear();
                                m1.clear();

                                int m = line.length() / 2;
                                insert(line.substr(0, m), m0);
                                insert(line.substr(m), m1);

                                map<char, int> intersect;
                                set_intersection(begin(m0), end(m0),
                                                 begin(m1), end(m1),
                                                 inserter(intersect, begin(intersect)));

                                for (const auto& [k, v] : intersect) {
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

        // problem 2
        sum = 0;
        if (!parse_file(input, 3, [&](const vector<string>& string_list) -> bool {
            map<char, int> m0, m1, m2;
            insert(string_list[0], m0);
            insert(string_list[1], m1);
            insert(string_list[2], m2);

            map<char, int> m0m1;
            set_intersection(begin(m0), end(m0),
                             begin(m1), end(m1),
                             inserter(m0m1, begin(m0m1)));
            map<char, int> m0m1m2;
            set_intersection(begin(m0m1), end(m0m1),
                             begin(m2), end(m2),
                             inserter(m0m1m2, begin(m0m1m2)));
            //map_out(m0m1m2);

            for (const auto& [k, v] : m0m1m2)
                sum += v;

            return true;
        })) {
            cout << "Some error parsing the input file." << endl;
        }
        cout << "priority sum = " << sum << endl;

    }

    void map_out(map<char, int> &m) {
        for (const auto& [k, v] : m) {
            cout << "[" << k << "," << v << "] ";
        }
        cout << endl;
    }

    void insert(const string &line, map<char, int> &m) {
        int n = line.size();
        for (int i = 0; i < n; ++i) {
            char ch = line[i];
            m.insert(pair{ch, priority(ch)});
        }
        //cout << line << "(" << n << "," << m.size() << ")" << endl;
    }

    int priority(char item) {
        int priority = letter_map[tolower(item)];
        if (isupper(item))
            priority += 26;
        return priority;
    }

};

#endif //ADVENT_OF_CODE_2022_DAY2_H
