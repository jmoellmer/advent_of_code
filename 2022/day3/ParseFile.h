#ifndef ADVENT_OF_CODE_2022_PARSEFILE_H
#define ADVENT_OF_CODE_2022_PARSEFILE_H

#include <fstream>
#include <functional>
#include <string>
using namespace std;

static bool parse_file(string input, std::function<bool(const string&)> parse_line) {
    ifstream ifs;
    ifs.open(input);

    if (!ifs.is_open())
        return false;

    for (string line; getline(ifs, line);) {
        if (!parse_line(line))
            return false;
    }

    ifs.close();
    return true;
}
#endif //ADVENT_OF_CODE_2022_PARSEFILE_H
