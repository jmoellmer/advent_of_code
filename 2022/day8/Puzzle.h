#ifndef ADVENT_OF_CODE_PUZZLE_H
#define ADVENT_OF_CODE_PUZZLE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../ParseFile.h"

class Puzzle {
private:
    vector<vector<int>> input_grid;
    vector<vector<int>> ans_grid;
    int n_rows=0, n_cols=0;

public:
    Puzzle(string input) {
        if (!parse_file(input, 1,
                        [&](const vector<string> &lines) {
                            load_grid(lines);
                            return true;
                        }
        )) {
            cout << "Some error with the input file." << endl;
        }

        assert(n_rows == n_cols);

        ans_grid.resize(n_cols);
        for (int r = 0; r < n_rows; ++r)
            ans_grid[r].resize(n_cols);

        for (int i = 0; i < n_rows; ++i)
            for (int j = 0; j < n_cols; ++j)
                ans_grid[i][j] = 0;

        for (int i = 1; i < n_rows - 1; ++i) {
            for (int j = 1; j < n_cols - 1; ++j) {
                if (is_visible(i, j))
                    ans_grid[i][j] = 1;
                else
                    ans_grid[i][j] = 0;
            }
        }

        int halo_trees = 2 * (n_rows) + 2 * (n_cols) - 4;
        cout << "halo_trees = " << halo_trees << endl;
        int sum = 0;
        for (int i = 1; i < n_rows - 1; ++i)
            for (int j = 1; j < n_cols - 1; ++j)
                sum += ans_grid[i][j];

        cout << "visible trees outside the grid: " << sum + halo_trees << endl;


        cout << "done.";
    }

    bool is_visible(int row, int col) {
        if (see_from_left(row, col))
            return true;
        else if (see_from_right(row, col))
            return true;
        else if (see_from_top(row, col))
            return true;
        else if (see_from_bottom(row, col))
            return true;
        return false;
    }

    bool see_from_left(int row, int col) {
        for (int c = 0; c < col; ++c)
            if (input_grid[row][c] >= input_grid[row][col])
                return false;
        return true;
    }

    bool see_from_right(int row, int col) {
        for (int c = col + 1; c < n_cols; ++c)
            if (input_grid[row][c] >= input_grid[row][col])
                return false;
        return true;
    }

    bool see_from_top(int row, int col) {
        for (int r = 0; r < row; ++r)
            if (input_grid[r][col] >= input_grid[row][col])
                return false;
        return true;
    }

    bool see_from_bottom(int row, int col) {
        for (int r = row + 1; r < n_rows; ++r)
            if (input_grid[r][col] >= input_grid[row][col])
                return false;
        return true;
    }


    bool visible(int target_tree, int tree) {
        if (tree >= target_tree)
            return false;
        return true;
    }

    void load_grid(const vector<string> &lines) {
        if (n_cols == 0) {
            n_cols = lines[0].length();
            input_grid.resize(n_cols);
        }
        input_grid[n_rows].resize(n_cols);

        for (int col = 0; col < n_cols; ++col) {
            stringstream ss;
            ss << lines[0][col];
            ss >> input_grid[n_rows][col];
        }

        n_rows++;
    }

    void print_grid(const vector<vector<int>>& grid) {
        cout << n_rows << " X " << n_cols << endl;
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j)
                cout << grid[i][j];
            cout << endl;
        }
    }
};

#endif //ADVENT_OF_CODE_PUZZLE_H
