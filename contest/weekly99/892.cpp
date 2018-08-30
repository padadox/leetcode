
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
    int surfaceArea(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }

        int sum = 0;
        int zero_cnt = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid.size(); ++j) {
                if(grid[i][j] == 0) {
                    continue;
                }

                if(i == 0) {
                    sum += grid[i][j];
                }
                else {
                    sum += max(0, grid[i][j] - grid[i-1][j]);
                }
                if(j == 0) {
                    sum += grid[i][j];
                }
                else {
                    sum += max(0, grid[i][j] - grid[i][j-1]);
                }
                if(i == grid.size()-1) {
                    sum += grid[i][j];
                }
                else {
                    sum += max(0, grid[i][j] - grid[i+1][j]);
                }
                if(j == grid.size()-1) {
                    sum += grid[i][j];
                }
                else {
                    sum += max(0, grid[i][j] - grid[i][j+1]);
                }

                sum += 2;
            }
        }

        sum += (grid.size() * grid.size() - zero_cnt) * 2;

        return sum;
    }
};
