#define CATCH_CONFIG_MAIN // provides main(); this line is required in only one .cpp file
#include "catch2/catch_all.hpp"
#include "Puzzle.h"

int sum_files(shared_ptr<Node> node) {
    int sum = 0;

    for (auto item : node->children) {
        sum += sum_files(item.second);
    }

    if (node->size != -1)
        sum += node->size;

    return sum;
}

void make_parent_node(Puzzle& p, vector<string> child_dirs) {
    p.build_tree(vector<string>{"$", "cd", "/"});
    p.build_tree(vector<string>{"$", "ls"});
    p.build_tree(vector<string>{"1", "file1"});
    for (auto& dir : child_dirs)
        p.build_tree(vector<string>{"dir", dir});

}

void make_node(Puzzle& p, string parent_dir, string child_dir) {
    p.build_tree(vector<string>{"$", "cd", parent_dir});
    p.build_tree(vector<string>{"$", "ls"});
    p.build_tree(vector<string>{"1", "file1"});
    p.build_tree(vector<string>{"dir", child_dir});
}

void make_end_node(Puzzle& p, string parent_dir) {
    p.build_tree(vector<string>{"$", "cd", parent_dir});
    p.build_tree(vector<string>{"$", "ls"});
    p.build_tree(vector<string>{"1", "file1"});
}

void up(Puzzle& p, int n) {
    while (n > 0) {
        p.build_tree(vector<string>{"$", "cd", ".."});
        n--;
    }
}

TEST_CASE( "Data Structures" ) {
    Puzzle p("");

    make_parent_node(p, vector<string>{"a", "aa", "aaa"});

    make_node(p, "a", "b");
    make_node(p, "b", "c");
    make_node(p, "c", "d");
    make_node(p, "d", "e");
    make_node(p, "e", "f");
    make_node(p, "f", "g");
    make_end_node(p, "g");

    up(p, 7);

    make_node(p, "aa", "bb");
    make_node(p, "bb", "cc");
    make_node(p, "cc", "dd");
    make_node(p, "dd", "ee");
    make_node(p, "ee", "ff");
    make_node(p, "ff", "gg");
    make_end_node(p, "gg");

    up(p, 7);

    make_node(p, "aaa", "bbb");
    make_node(p, "bbb", "ccc");
    make_node(p, "ccc", "ddd");
    make_node(p, "ddd", "eee");
    make_node(p, "eee", "fff");
    make_node(p, "fff", "ggg");
    make_end_node(p, "ggg");


    cout << "----------" << endl;
    p.print_tree(p.root_, 0);
    cout << "----------" << endl;

    int s = sum_files(p.root_);

    REQUIRE(s == 22);


}