// 20181018 16:51
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

using int64 = long long;
using pii = pair<int,int>;
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const int64 MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



/**
 * 问题描述
 *
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
 */


/**
 * 解决方案
 * 深度优先搜索，需要注意可选集合的动态变化。
 * 可以考虑使用小头堆管理待填充位置，但由于管理成本较高，可能实际并不合算。
 */

class Solution {
    using int_set = int;
    using int_set_vec = vector<int_set>;
    const int ALL_COND = 0x1ff;
    vector<int> row_cond;
    vector<int> col_cond;
    vector<int> box_cond;
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        row_cond.resize(n, ALL_COND);
        col_cond.resize(n, ALL_COND);
        box_cond.resize(n, ALL_COND);

        vector<pair<int, int>> empty_grid;
        empty_grid.reserve(n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {
                    empty_grid.emplace_back(i, j);
                    continue;
                }

                int c = board[i][j] - '0';
                remove(i, j, c);
            }
        }

        vector<int> fill(empty_grid.size(), 0);

        int i = 0;
        int cnt = 0;
        for(; i >= 0 && i < empty_grid.size(); ) {
            int r, c;
            tie(r, c) = empty_grid[i];
            int box_id = (r / 3) * 3 + (c / 3);

            cnt++;

            int cur = fill[i];
            if(cur > 0) {
                add(r, c, cur);
            }

            int cond = get(r, c);
            for(cur++; cur <= 9; cur++) {
                if(0 == ((1 << (cur-1)) & cond)) {
                    continue;
                }

                remove(r, c, cur);
                board[r][c] = '0' + cur;
                fill[i] = cur;
                i++;
                break;
            }

            if(cur > 9) {
                fill[i] = 0;
                board[r][c] = '.';
                i--; 
            }
        }

        cout << "cnt = " << cnt << endl;
    }

private:
    inline void add_cond(int i, int& m) {
        // i >= 1
        m |= 1 << (i-1);
    }

    inline void remove_cond(int i, int& m) {
        m &= ~(1 << (i-1));
    }

    inline int inter_cond(int a, int b, int c) {
        return a & b & c;
    }

    void remove(int r, int c, int v) {
        int box_id = (r / 3) * 3 + (c / 3);
        remove_cond(v, row_cond[r]);
        remove_cond(v, col_cond[c]);
        remove_cond(v, box_cond[box_id]);
    }

    void add(int r, int c, int v) {
        int box_id = (r / 3) * 3 + (c / 3);
        add_cond(v, row_cond[r]);
        add_cond(v, col_cond[c]);
        add_cond(v, box_cond[box_id]);
    }

    int get(int r, int c) {
        int box_id = (r / 3) * 3 + (c / 3);
        return inter_cond(row_cond[r], col_cond[c], box_cond[box_id]);
    }

};


int main(int argc, const char *argv[])
{
    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    Solution().solveSudoku(board);
    return 0;
}
