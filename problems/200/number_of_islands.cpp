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

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/*
 *
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int ans = 0;
        for(size_t i = 0; i < grid.size(); i++) {
            for(size_t j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '0') {
                    continue;
                }

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                grid[i][j] = '0';
                while(!q.empty()) {
                    auto x = q.front();
                    q.pop();

                    int a = x.first;
                    int b = x.second;

                    int dir[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
                    for(auto& d: dir) {
                        int m = a + d[0];
                        int n = b + d[1];

                        if(m < 0 || m >= grid.size() || n < 0 || n >= grid[m].size()) {
                            continue;
                        }

                        if(grid[m][n] == '0') {
                            continue;
                        }

                        q.push(make_pair(m, n));
                        grid[m][n] = '0';
                    }

                }
                ans++;
            }
        }
        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<vector<char>> A
   // {{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
   //{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
{
{'1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','0','1','1','1','0','1','0','1','0','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','0','0','0','1','1','1','1','0','0'},
{'1','0','1','0','1','1','1','1','0','1','0','1','0','1','1','0','1','1','1','1'},
{'1','0','1','1','1','1','1','1','0','1','1','0','0','1','1','1','0','1','1','1'},
{'0','1','1','1','1','1','0','1','1','0','1','0','0','1','1','1','0','1','1','1'},
{'1','1','1','1','1','1','1','1','0','1','1','1','0','1','0','1','1','1','1','1'},
{'1','1','1','1','1','0','1','1','1','1','1','0','1','0','1','0','1','0','1','1'},
{'0','1','1','1','1','1','1','1','0','1','0','1','1','0','1','1','1','0','0','1'},
{'0','1','0','0','0','1','1','1','1','1','1','0','1','1','1','0','1','0','1','0'},
{'0','1','1','1','1','1','1','1','1','1','0','0','0','0','1','1','1','1','1','1'},
{'1','0','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1'},
{'1','1','1','1','1','1','0','1','0','1','1','0','1','0','1','1','1','1','1','1'},
{'1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0'},
{'1','1','0','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},
{'1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','0','0','1'},
{'1','0','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1'},
{'1','0','0','1','1','1','0','0','1','1','0','1','1','1','0','0','1','1','1','1'},
{'1','1','1','0','1','1','0','0','0','1','0','0','1','1','1','1','0','0','1','1'},
{'1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','0','1'}};
    cout << Solution().numIslands(A) << endl;
    return 0;
}
