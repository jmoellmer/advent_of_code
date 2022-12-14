#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <list>
#include <set>
using namespace std;

#include "../ParseFile.h"
class Puzzle {
private:
    using coord = pair<int, int>;
    struct Rope {
        Rope(coord head, coord tail) : head(head), tail(tail) { }
        coord head;
        coord tail;
    };

    list<Rope> rope;

public:
    Puzzle(string input) {

        rope.push_back(Rope({0,0}, {0,0}));

        if (!parse_file(input, 1,
                        [&](const vector<string> &lines) {
                            vector<string> tokens = split(lines[0]);
                            char direction = tokens[0].data()[0];
                            int n = stoi(tokens[1]);

                            switch (direction) {
                                case 'U': move_up(n);    break;
                                case 'D': move_down(n);  break;
                                case 'L': move_left(n);  break;
                                case 'R': move_right(n); break;
                                default:
                                    cout << "Received unknown command." << endl;
                                    break;
                            }
                            cout << "Processed: " << tokens[0] << " " << tokens[1] << endl;
                            return true;
                        }

        )) {
            cout << "Some error with the input file." << endl;
        }

        set<coord> tails;
        for (auto it = begin(rope); it != end(rope); ++it)
            tails.insert((*it).tail);

        cout << "the tail visited at least once: " << tails.size() << " positions" << endl;

    }

    void move_up(int n) {
        coord head = rope.back().head;
        coord tail = rope.back().tail;

        for (int i = 0; i < n; ++i) {
            up(head);
            if (dist(head, tail).second > 1) {
                tail.first = head.first;
                up(tail);
            }
            add(head, tail);
        }
    }

    void move_down(int n) {
        coord head = rope.back().head;
        coord tail = rope.back().tail;

        for (int i = 0; i < n; ++i) {
            down(head);
            if (dist(head, tail).second > 1) {
                tail.first = head.first;
                down(tail);
            }
            add(head, tail);
        }
    }

    void move_left(int n) {
        coord head = rope.back().head;
        coord tail = rope.back().tail;

        for (int i = 0; i < n; ++i) {
            left(head);
            if (dist(head, tail).first > 1) {
                tail.second = head.second;
                left(tail);
            }
            add(head, tail);
        }
    }

    void move_right(int n) {
        coord head = rope.back().head;
        coord tail = rope.back().tail;

        for (int i = 0; i < n; ++i) {
            right(head);
            if (dist(head, tail).first > 1) {
                tail.second = head.second;
                right(tail);
            }
            add(head, tail);
        }
    }

    void up(coord& a) {
        a.second++;
    }

    void down(coord& a) {
        a.second--;
    }

    void left(coord& a) {
        a.first--;
    }

    void right(coord& a) {
        a.first++;
    }

    void add(coord head, coord tail) {
        rope.push_back(Rope{head, tail});
    }

    coord dist(coord head, coord tail) {
        return coord{abs(head.first - tail.first), abs(head.second - tail.second)};
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
