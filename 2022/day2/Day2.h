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
static map<string, bonus> bonusMap = {
        {"X", LOSE}, {"Y", DRAW}, {"Z", WIN}
};
static map<hand, hand> winMap = {
        {R, P}, {P, S}, {S, R}
};
static map<hand, hand> loseMap = {
        {R, S}, {P, R}, {S, P}
};

using play = tuple<hand, hand>;

class Day2 {
private:
    stack<play> plays;
    string input;

private:
    vector<string> splitLine(const string &line) const;
    hand getYourHand(bool xyz, const string &y_str, const hand &o) const;

    auto pop_play() {
        auto& top = plays.top();
        plays.pop();
        return top;
    }

    bonus winner(hand o, hand y) {
        if (o == y)
            return DRAW;
        else if ((y == R && o == S) || (y == S && o == P) || (y == P && o == R))
            return WIN;
        else
            return LOSE;
    }

public:
    Day2(string input) : input(input) {
        if (!parse(input)) {
            cout << "Error parsing " << input << endl;
        }
    }

    void reload() {
        plays = {};
        if (!parse(input, true)) {
            cout << "Error parsing " << input << endl;
        }
    }

    bool parse(string input, bool xyz = false);

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
