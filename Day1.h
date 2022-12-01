//
// Created by Jeff Moellmer on 12/1/22.
//

#ifndef ADVENT_OF_CODE_2022_DAY1_H
#define ADVENT_OF_CODE_2022_DAY1_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Day1 {
private:
    string inFileName{};
    vector<int> caloriesTable{};
public:
    Day1(string inFileName) : inFileName(inFileName) {
        if (parseInput() == -1) {
            cout << "Error parsing input." << endl;
        }
    }

    int max() const {
        return *(max_element(begin(caloriesTable), end(caloriesTable)));
    }

    int top3() {
        sort(begin(caloriesTable), end(caloriesTable), greater<int>());
        return caloriesTable[0] + caloriesTable[1] + caloriesTable[2];
    };

    int parseInput();

};


#endif //ADVENT_OF_CODE_2022_DAY1_H
