#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

#include "../ParseFile.h"

struct Node {
    Node(string name, int size, Node* parent) : name(name), size(size), parent(parent) { }
    string name;
    int size; // a size of -1 means its a directory
    Node* parent;
    unordered_map<string, Node*> children;

};

class Puzzle {
    unique_ptr<Node> root{nullptr};

public:
    Puzzle(string input) {
        if (!parse_file(input, 1, [&](const vector<string>& lines) {
            auto tokens = split(lines[0]);
            if (tokens[0] == "$" && tokens[1] == "cd") {
                if (tokens[2] == "/") {
                    root = make_unique<Node>("/", -1, nullptr);
                } else if (tokens[2] == "..") {
                    cout << "go up a directory" << endl;
                } else {
                    cout << "cd " << tokens[2] << endl;
                }
            } else if (tokens[0] == "$" && tokens[1] == "ls") {
                cout << "ls dir: " << root->name << endl;
            } else if (tokens[0] == "dir") { // output is a file
                cout << "dir: " << tokens[1] << endl
                root->children.insert({tokens[1], root});
            } else {
                cout << "file: " << tokens[0] << " " << tokens[1] << endl;
            }
            return true;
        })) {
            cout << "Some error with the input file." << endl;
        }
        cout << "Done." << endl;
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
