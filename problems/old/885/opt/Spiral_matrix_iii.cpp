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
        int len = 0;
        int x = r0;
        int y = c0;

        vector<vector<int> > result;
        size_t n = R * C;
        result.reserve(n);
        result.push_back(vector<int>{x, y});

        int upper[] = {C, R, C, R};
        int *axis[] = {&y, &x, &y, &x};
        int direct[] = {1, 1, -1, -1};

        while (result.size() < n) {
            len++;
            int i = 0;
            if(0 <= x && x < R) {
                if(y < -1) {
                    i = -1 - y;
                    y = -1;
                }

                for(; ++i <= len && ++y < C;) {
                    result.push_back(vector<int>{x, y});
                }
                if(i > len) {
                    i--;
                }
            }
            y += len - i;

            i = 0;
            if(0 <= y && y < C) {
                if(x < -1) {
                    i = -1 - x;
                    x = -1;
                }
                for(; ++i <= len && ++x < R;) {
                    result.push_back(vector<int>{x, y});
                }
                if(i > len) {
                    i--;
                }
            }
            x += len - i;

            len++;
            i = 0;
            if(0 <= x && x < R) {
                if(y > C) {
                    i += y - C;
                    y = C;
                }
                for(; ++i <= len && --y >= 0;) {
                    result.push_back(vector<int>{x, y});
                }
                if(i > len) {
                    i--;
                }
            }
            y -= len - i;

            i = 0;
            if(0 <= y && y < C) {
                if(x > R) {
                    i += x - R;
                    x = R;
                }
                for(; ++i <= len && --x >= 0;) {
                    result.push_back(vector<int>{x, y});
                }
                if(i > len) {
                    i--;
                }
            }
            x -= len - i;
        }

        result.resize(n);
        return result;
    }
};


int main(int argc, const char *argv[])
{
    Solution s;
    vector<vector<int> > result = s.spiralMatrixIII(5, 6, 1, 4);

    return 0;
}
