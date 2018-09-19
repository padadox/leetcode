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


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row_max(grid.size());
        vector<int> col_max(grid.size());

        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid.size(); ++j) {
                if(grid[i][j] > row_max[i]) {
                    row_max[i] = grid[i][j];
                }

                if(grid[i][j] > col_max[j]) {
                    col_max[j] = grid[i][j];
                }
            }
        }

        int ans = 0;
        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid.size(); ++j) {
                ans += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<vector<int>> grid {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << Solution().maxIncreaseKeepingSkyline(grid);
    return 0;
}
