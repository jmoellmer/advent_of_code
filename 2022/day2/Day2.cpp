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
    if (xyz)
        y = decodePlay(y_str, o);
    else
        y = handMap[y_str];

    return y;
}

hand Day2::decodePlay(const string &y_str, const hand &o) const {
    hand y;
    bonus b = bonusMap[y_str];
    switch(b) {
        case LOSE: y = loseMap[o]; break;
        case DRAW: y = o; break;
        case WIN: y = winMap[o]; break;
    }
    return y;
}

vector<string> Day2::splitLine(const string &line) const {
    stringstream ss(line);
    string hand;
    vector<string> v;
    while (ss >> hand)
        v.push_back(hand);
    return v;
}
