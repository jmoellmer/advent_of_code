//
// Created by Jeff Moellmer on 12/1/22.
//

#include "Day1.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int Day1::max() const {

    string inFileName = "../data/input";
    ifstream inFile;
    inFile.open(inFileName);

    vector<int> caloriesTable{};

    int calories = 0;
    if (inFile.is_open()) {
        for (string line; getline(inFile, line); ) {
            if (!line.empty()) {
                calories += stoi(line);
            } else if (calories != 0) {
                caloriesTable.push_back(calories);
                calories = 0;
            }
        }

        inFile.close();
    } else {
        cout << "Cannot open file: " << inFileName << endl;
        return -1;
    }

    auto it = max_element(begin(caloriesTable), end(caloriesTable));
    return *it;
}