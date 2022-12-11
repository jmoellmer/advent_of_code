#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <memory>
#include <map>
using namespace std;

#include "../ParseFile.h"

struct Node {
    Node(string name, int size, shared_ptr<Node> parent) : 
        name(name), size(size), parent(parent) { }

    string name;
    int size; // a size of -1 means its a directory
    shared_ptr<Node> parent;
    map<string, shared_ptr<Node>> children;
};

class Puzzle {
public:
    shared_ptr<Node> root_{nullptr};
    shared_ptr<Node> current_{nullptr};
    multimap<string, int> dir_size_map_;

public:
    void build_tree(const vector<string>& tokens) {
        if (tokens[0] == "$" && tokens[1] == "cd") {
            if (tokens[2] == "/") {
                if (root_ == nullptr)
                    root_ = make_shared<Node>("/", -1, nullptr);
                current_ = root_;
            } else if (tokens[2] == "..") {
                cout << "go up a directory" << endl;
                assert(current_ != nullptr);
                assert(current_->parent != nullptr);
                current_ = current_->parent;
            } else {
                string dirname = tokens[2];
                cout << "cd " << dirname << endl;
                assert(current_ != nullptr);
                assert(current_->children.count(dirname) == 1);
                assert(current_->children[dirname] != nullptr);
                current_ = current_->children[dirname];
            }
        } else if (tokens[0] == "$" && tokens[1] == "ls") {
            stack<string> dirs;
            assert(current_ != nullptr);
            shared_ptr<Node> tmp = current_;
            dirs.push(tmp->name);
            while (tmp->parent != nullptr) {
                tmp = tmp->parent;
                dirs.push(tmp->name);
            }

            cout << "ls dir: ";
            while (dirs.size() != 0) {
                string dir = dirs.top();
                if (dir != "/")
                    cout << "/";
                cout << dir;
                dirs.pop();
            }
            cout << endl;
        } else if (tokens[0] == "dir") { // output is a file
            string dirname = tokens[1];
            cout << "\tdir: " << dirname << endl;
            assert(current_ != nullptr);
            current_->children.emplace(dirname, make_shared<Node>(dirname, -1, current_));
        } else {
            int filesize = stoi(tokens[0]);
            string filename = tokens[1];
            cout << "\tfile: " << filesize << " " << filename << endl;
            assert(current_ != nullptr);
            current_->children.emplace(filename, make_shared<Node>(filename, filesize, current_));
        }
    }

public:
    Puzzle(string input) {
        if (input.empty()) {
            cout << "input file is empty" << endl;
            return;
        }
        if (!parse_file(input, 1, [  &](const vector<string>& lines) {
            build_tree(split(lines[0]));
            return true;
        })) {
            cout << "Some error with the input file." << endl;
        }

        print_tree(root_, 0);

        sum_file_sizes(root_);

        const int MAX = 100'000;
        int sum = 0;
        for (auto item : dir_size_map_) {
            
            cout << item.first << ": " << item.second;
            if(item.second <= MAX) {
                cout << "+";
                sum += item.second;
            }
            cout << endl;
        }
        cout << "sum of total sizes: " << sum << endl;

        cout << "Done." << endl;
    }

    void print_node(shared_ptr<Node> node) {
        cout << node->name << endl;
        for (const auto& i : node->children ) {
            cout << "\t" << i.first << " ";
        }
        cout << endl;
    }

    void print_tree(shared_ptr<Node> node, int level) {
        
        for (int i = 0; i < level; i++)
            cout << "\t";
        cout << node->name;
        if (node->size == -1)
            cout << "/";
        else
            cout << "(" << node->size << ")";
        cout << endl;

        level++;
        for (auto item : node->children) {
            print_tree(item.second, level);
        }                
    }

    int sum_file_sizes(shared_ptr<Node> node) {
        int sum = 0;
        
        for (auto item : node->children) {
            sum += sum_file_sizes(item.second);
        }
        
        if (node->size != -1)
            sum += node->size;
        else {
            assert(node->size == -1);
            dir_size_map_.insert(pair<string, int>{node->name, sum});
        }
        
        return sum;
    }


};

#endif //ADVENT_OF_CODE_PUZZLE_H
