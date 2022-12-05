#ifndef ADVENT_OF_CODE_2022_PARSEFILE_H
#define ADVENT_OF_CODE_2022_PARSEFILE_H

#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

static bool parse_file(string input, int num_lines, std::function<bool(const vector<string>&)> parse_line) {
    ifstream ifs;
    ifs.open(input);

    if (!ifs.is_open())
        return false;

    int i = 0;
    vector<string> string_list;
    for (string line; getline(ifs, line);) {
        if (line.empty())
            continue;
        string_list.push_back(line); //cout << "." << flush;
        //cout << line << endl;
        if (++i % num_lines == 0) {
            if (!parse_line(string_list))
                return false;
            string_list.clear();
            //cout << num_lines << flush;
        }
    }
    //cout << endl;
    ifs.close();
    return true;
}
#endif //ADVENT_OF_CODE_2022_PARSEFILE_H
