/*
On a 2 dimensional grid with R rows and C columns, we start at (r0, c0) facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid. 

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.) 

Eventually, we reach all R * C spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

 

Example 1:

Input: R = 1, C = 4, r0 = 0, c0 = 0
Output: [[0,0],[0,1],[0,2],[0,3]]


 

Example 2:

Input: R = 5, C = 6, r0 = 1, c0 = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]



Note:

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C
*/

#include <iostream>
#include <vector>
using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int> > result;
        size_t n = R * C;
        result.reserve(n);

        int len = 0;
        int x = r0;
        int y = c0;
        int upper[] = {C, R, C, R, C};
        int *axis[] = {&y, &x, &y, &x, &y};
        int direct[] = {1, 1, -1, -1, 1};
        int idx = -1;

        result.push_back(vector<int>{x, y});
        while (result.size() < n) {
            idx++;
            idx %= 4;
            if(idx % 2 == 0) {
                len++;
            }

            // b is the one who changes.
            int a_idx = idx + 1;
            int b_idx = idx;
            int &a = *axis[a_idx];
            int &b = *axis[b_idx];

            int a_upper = upper[a_idx];
            int b_upper = upper[b_idx];

            if(a < 0 || a >= a_upper) {
                b += len * direct[b_idx];
                continue;
            }

            for(int i = 0; i < len; i++) {
                b += direct[b_idx];
                if(0 <= b && b < b_upper) {
                    result.push_back(vector<int>{x, y});
                }
            }
        }

        return result;
    }
};


int main(int argc, const char *argv[])
{
    Solution s;
    vector<vector<int> > result = s.spiralMatrixIII(5, 6, 1, 4);

    return 0;
}
