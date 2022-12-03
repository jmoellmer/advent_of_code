#ifndef ADVENT_OF_CODE_2022_DAY2_H
#define ADVENT_OF_CODE_2022_DAY2_H

#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <stack>
using namespace std;

enum hand {R = 1, P, S};
enum bonus {LOSE=0, DRAW=3, WIN=6};
static map<string, hand> handMap = {
        {"A", R}, {"B", P}, {"C", S},
        {"X", R}, {"Y", P}, {"Z", S}
};

using play = tuple<hand, hand>;

class Day2 {
private:
    stack<play> plays;

private:
    auto pop_play() {
        auto& top = plays.top();
        plays.pop();
        return top;
    }

    bonus winner(hand o, hand y) {
        if ((o == R && y == R) || (o == P && y == P) || (o == S && y == S)) {
            return DRAW;
        } else if ((y == R && o == S) || (y == S && o == P) || (y == P && o == R)) {
            return WIN;
        } else {
            return LOSE;
        }
    }

public:
    Day2(std::string input) {
        if (!parse(input)) {
            cout << "Error parsing " << input << endl;
        }
    }

    bool parse(string input);

    int pop_score() {
        auto play = pop_play();
        hand y = get<1>(play);
        return y + winner(get<0>(play), y);
    }

    bool more_scores() const {
        return plays.size() > 0;
    }
};

#endif //ADVENT_OF_CODE_2022_DAY2_H
