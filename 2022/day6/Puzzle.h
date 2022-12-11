#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
using namespace std;

#include "../ParseFile.h"

struct Node {
    Node(string name, int size, shared_ptr<Node> parent) : name(name), size(size), parent(parent) { }
    string name;
    int size;
    shared_ptr<Node> parent;
    map<string, shared_ptr<Node>> children;
};

class Puzzle {
public:
    shared_ptr<Node> root_{nullptr}, current_{nullptr};
    multimap<string, int> dir_size_map_;

public:
    void build_tree(const vector<string>& tokens) {
        if (tokens[0] == "$" && tokens[1] == "cd")
            if (tokens[2] == "/")
                current_ = root_;
            else if (tokens[2] == "..")
                current_ = current_->parent;
            else
                current_ = current_->children[tokens[2]];
        else if (tokens[0] == "$" && tokens[1] == "ls")
            return;
        else if (tokens[0] == "dir")
            current_->children.emplace(tokens[1], make_shared<Node>(tokens[1], -1, current_));
        else
            current_->children.emplace(tokens[1], make_shared<Node>(tokens[1], stoi(tokens[0]), current_));
    }

public:
    Puzzle(string input) {
        if (input.empty())
            return;

        root_ = make_shared<Node>("/", -1, nullptr);

        if (!parse_file(input, 1,
                        [&](const vector<string> &lines) {
                            build_tree(split(lines[0]));
                            return true;
                        }
        )) {
            cout << "Some error with the input file." << endl;
        }

        sum_file_sizes(root_);

        int sum = 0;
        for (auto item : dir_size_map_)
            if(item.second <= 100'000)
                sum += item.second;

        cout << "sum of total sizes: " << sum << endl;
    }

    int sum_file_sizes(shared_ptr<Node> node) {
        int sum = 0;
        
        for (auto item : node->children)
            sum += sum_file_sizes(item.second);
        
        if (node->size != -1)
            sum += node->size;
        else
            dir_size_map_.insert(pair<string, int>{node->name, sum});
        
        return sum;
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
