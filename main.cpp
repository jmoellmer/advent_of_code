#include <iostream>
#include "Day1.h"
using namespace std;

int main() {
    cout << "Hello, Advent of Code!" << endl;

    // Day 1
    cout << "Day 1:" << endl;
    Day1 d1("../data/input");
    cout << "\tmax calories = " << d1.max() << endl;
    cout << "\tsummed top3 = " << d1.top3() << endl;

    return 0;
}
