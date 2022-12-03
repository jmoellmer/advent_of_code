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
        vector<string> v;
        istringstream ss(line);
        while (!ss.eof()) {
            string hand;
            getline(ss, hand, ' ');
            v.push_back(hand);
        }

        hand o = handMap[v[0]];
        hand y;

        if (xyz) {
            bonus b = bonusMap[v[1]];
            switch(b) {
                case LOSE: y = loseMap[o]; break;
                case DRAW: y = o; break;
                case WIN: y = winMap[o]; break;
            }
        } else {
            y = handMap[v[1]];
        }

        plays.push(play{o, y});
    }

    ifs.close();
    return true;
}