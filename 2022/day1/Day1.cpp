//
// Created by Jeff Moellmer on 12/1/22.
//

#include "Day1.h"
#include <fstream>

int Day1::parseInput() {
    if (inFileName.empty()) {
        return -1;
    }

    ifstream inFile;
    inFile.open(inFileName);

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
    return 0;
}