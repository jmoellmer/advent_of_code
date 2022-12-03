#include "Day2.h"
#include <fstream>
#include <sstream>
#include <vector>

bool Day2::parse(string input, bool xyz) {
    ifstream ifs;
    ifs.open(input);

    if (!ifs.is_open())
        return false;

    for (string line; getline(ifs, line);) {
        vector<string> v = splitLine(line);
        hand o = handMap[v[0]];
        hand y = getYourHand(xyz, v[1], o);
        plays.push(play{o, y});
    }

    ifs.close();
    return true;
}

hand Day2::getYourHand(bool xyz, const string &y_str, const hand &o) const {
    hand y;
    if (xyz) {
        bonus b = bonusMap[y_str];
        switch(b) {
            case LOSE: y = loseMap[o]; break;
            case DRAW: y = o; break;
            case WIN: y = winMap[o]; break;
        }
    } else {
        y = handMap[y_str];
    }
    return y;
}

vector<string> Day2::splitLine(const string &line) const {
    vector<string> v;
    istringstream ss(line);
    while (!ss.eof()) {
        string hand;
        getline(ss, hand, ' ');
        v.push_back(hand);
    }
    return v;
}
