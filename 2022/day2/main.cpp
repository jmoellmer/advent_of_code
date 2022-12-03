#include <iostream>
#include "Day2.h"

using namespace std;

int main() {
    cout << "Hello, Advent of Code, Day 2!" << endl;

    Day2 d2("../input");

    int total = 0;
    while (d2.more_scores()) {
        total += d2.pop_score();
    }

    cout << "grand total = " << total << endl;

    d2.reload();
    total = 0;
    while (d2.more_scores()) {
        total += d2.pop_score();
    }

    cout << "grand XYZ total = " << total << endl;

    return 0;
}
