/*
 * 问题描述
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (35.66%)
 * Total Accepted:    115K
 * Total Submissions: 322.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */


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



/*
 * 解决方案
 */



static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> flag(5*n-2, false);
        vector<string> queens(n, string(n, '.'));

        solve(ans, queens, 0, flag, n);

        return ans;
    }

    void solve(vector<vector<string>>& ans, vector<string>& queens, int row, vector<bool>& flag, int n) {
        if(row == n) {
            ans.push_back(queens);
            return;
        }

        for(int col = 0; col < n; col++) {
            int dig1 = n + (n - 1 - row + col);
            int dig2 = (3 * n - 1) + (row + col);

            if(flag[col] || flag[dig1] || flag[dig2]) {
                continue;
            }

            flag[col] = flag[dig1] = flag[dig2] = true;
            queens[row][col] = 'Q';
            solve(ans, queens, row+1, flag, n);
            queens[row][col] = '.';
            flag[col] = flag[dig1] = flag[dig2] = false;
        }
    }
};

