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

        // part 1
        int n_trees = 0;
        for (int i = 1; i < n_rows - 1; ++i) {
            for (int j = 1; j < n_cols - 1; ++j) {
                if (is_visible(i, j))
                   n_trees++;
            }
        }

        int halo_trees = 2 * (n_rows) + 2 * (n_cols) - 4;
        cout << "visible trees outside the grid: " << n_trees + halo_trees << endl;

        // part 2
       int max_score = 0;
        for (int i = 1; i < n_rows - 1; ++i)
            for (int j = 1; j < n_cols - 1; ++j)
                max_score = max(max_score, scenic_score(i, j));

        cout << "highest scenic score = " << max_score << endl;
        cout << "done.";
    }

    int scenic_score(int row, int col) {
        int score = 1;
        score *= n_from_left(row, col);
        score *= n_from_right(row, col);
        score *= n_from_top(row, col);
        score *= n_from_bottom(row, col);
        return score;
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

    int n_from_left(int row, int col) {
        if (col == 0) return 0;
        int n = 0;
        int h = input_grid[row][col];
        for (int c = col - 1; c >= 0; --c)
            if (input_grid[row][c] < h)
                n++;
            else if (input_grid[row][c] >= h) {
                n++;
                break;
            }
        return n;
    }

    int n_from_right(int row, int col) {
        if (col == n_cols - 1) return 0;
        int n = 0;
        int h = input_grid[row][col];
        for (int c = col + 1; c < n_cols; ++c)
            if (input_grid[row][c] < h)
                n++;
            else if (input_grid[row][c] >= h) {
                n++;
                break;
            }
        return n;
    }

    int n_from_top(int row, int col) {
        if (row == 0) return 0;
        int n = 0;
        int h = input_grid[row][col];
        for (int r = row - 1; r >= 0; --r)
            if (input_grid[r][col] < h)
                n++;
            else if (input_grid[r][col] >= h) {
                n++;
                break;
            }

        return n;
    }

    int n_from_bottom(int row, int col) {
        if (row == n_rows - 1) return 0;
        int n = 0;
        int h = input_grid[row][col];
        for (int r = row + 1; r < n_rows; ++r)
            if (input_grid[r][col] < h)
                n++;
            else if (input_grid[r][col] >= h) {
                n++;
                break;
            }
        return n;
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
};

#endif //ADVENT_OF_CODE_PUZZLE_H
