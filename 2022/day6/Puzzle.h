#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <utility>
#include <map>
using namespace std;

#include "../ParseFile.h"

struct Node {
    Node(string name, int size, shared_ptr<Node> parent) : 
    name(name), size(size), parent(parent) { }
    string name;
    int size; // a size of -1 means its a directory
    shared_ptr<Node> parent;
    unordered_map<string, shared_ptr<Node>> children;
};

class Puzzle {
    shared_ptr<Node> real_root{nullptr};
    shared_ptr<Node> root{nullptr};
    map<string, int> file_size_map;

public:
    Puzzle(string input) {
        if (!parse_file(input, 1, [&](const vector<string>& lines) {
            auto tokens = split(lines[0]);
            if (tokens[0] == "$" && tokens[1] == "cd") {
                if (tokens[2] == "/") {
                    real_root = make_shared<Node>("/", -1, nullptr);
                    root = real_root;
                } else if (tokens[2] == "..") {
                    cout << "go up a directory" << endl;
                    root = root->parent;
                } else {
                    string dirname = tokens[2];
                    cout << "cd " << dirname << endl;
                    root = root->children[dirname];
                }
            } else if (tokens[0] == "$" && tokens[1] == "ls") {
                cout << "ls dir: " << root->name << endl;
            } else if (tokens[0] == "dir") { // output is a file        
                string dirname = tokens[1];
                cout << "dir: " << dirname << endl;
                root->children.emplace(dirname, make_shared<Node>(dirname, -1, root));                             
            } else {
                int filesize = stoi(tokens[0]);
                string filename = tokens[1];
                cout << "file: " << filesize << " " << filename << endl;
                root->children.emplace(filename, make_shared<Node>(filename, filesize, root));
            }
            return true;
        })) {
            cout << "Some error with the input file." << endl;
        }

        print_tree(real_root, 0);

        sum_file_sizes(real_root);

        const int MAX = 100'000;
        int sum = 0;
        for (auto item : file_size_map) {
            
            cout << item.first << ": " << item.second << endl;
            if(item.second <= MAX) {                
                sum += item.second;
            }
        }
        cout << "sum of total sizes: " << sum << endl;

        cout << "Done." << endl;
    }

    void print_node(shared_ptr<Node> root) {
        cout << root->name << endl;
        for (const auto& i : root->children ) {
            cout << "\t" << i.first << " ";
        }
        cout << endl;
    }

    void print_tree(shared_ptr<Node> root, int level) {                        
        
        for (int i = 0; i < level; i++)
            cout << "\t";
        cout << root->name;
        if (root->size == -1)
            cout << "/";
        else
            cout << "(" << root->size << ")";
        cout << endl;

        level++;
        for (auto item : root->children) {                        
            print_tree(item.second, level);
        }                
    }

    int sum_file_sizes(shared_ptr<Node> root) {
        int sum = 0;
        
        for (auto item : root->children) {
            sum += sum_file_sizes(item.second);
        }
        
        if (root->size != -1)
            sum += root->size;
        else        
            file_size_map[root->name] = sum;
        
        return sum;
    }


};

#endif //ADVENT_OF_CODE_PUZZLE_H
