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


/**
 *Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.

Note:
Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.

Example:

Given the following 3x6 height map:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]

Return 4.
 *
 */

/*
class Solution {
    int m = 0;
    int n = 0;
    vector<vector<int>> deep;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }

        m = heightMap.size();
        n = heightMap[0].size();

        deep = heightMap;

        queue<pair<int, int>> q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                q.push(make_pair(i, j));
            }
        }

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            int i = cur.first;
            int j = cur.second;

            for(auto &x: dir) {
                int neighbour_i = i+x[0];
                int neighbour_j = j+x[1];

                if(neighbour_i <= 0 || neighbour_i >= m - 1) {
                    continue;
                }

                if(neighbour_j <= 0 || neighbour_j >= n - 1) {
                    continue;
                }

                int d = calc(neighbour_i, neighbour_j);
                if(d > deep[neighbour_i][neighbour_j]) {
                    deep[neighbour_i][neighbour_j] = d;
                    q.push(make_pair(neighbour_i, neighbour_j));
                }
            }
        }

        int ans = 0;
        for(size_t i = 1; i < m - 1; ++i) {
            for(size_t j = 1; j < n - 1; ++j) {
                if(deep[i][j] <= heightMap[i][j]) {
                    continue;
                }

                ans += deep[i][j] = heightMap[i][j];
            }
        }

        return ans;
    }

    int calc(int i, int j) {
        return min(min(deep[i-1][j], deep[i+1][j]), min(deep[i][j-1], deep[i][j+1])); 
    }
};
*/
class Solution {
    int m = 0;
    int n = 0;
    vector<vector<int>> deep;

    struct Cmp {
        vector<vector<int>>* heightMap;
        Cmp(vector<vector<int>>* heightMap) {
            this->heightMap = heightMap;
        }

        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return heightMap[a.first][a.second] > heightMap[b.first][b.second];
        }
    };

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size() < 3 || heightMap[0].size() < 3) {
            return 0;
        }

        m = heightMap.size();
        n = heightMap[0].size();

        auto func = [&](auto &a, auto &b) -> bool {
            return heightMap[a.first][a.second] > heightMap[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(func) > q(func);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i != 0 && i != m-1 && j != 0 && j != n-1) {
                    continue;
                }

                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }

        vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int ans = 0;
        while(!q.empty()) {
            auto cur = q.top();
            q.pop();

            for(auto &x: dir) {
                int i = cur.first + x[0];
                int j = cur.second + x[1];
                if(i <= 0 || i >= m-1) {
                    continue;
                }

                if(j <= 0 || j >= n-1) {
                    continue;
                }

                if(visited[i][j]) {
                    continue;
                }

                if(heightMap[i][j] < heightMap[cur.first][cur.second]) {
                    ans += heightMap[cur.first][cur.second] - heightMap[i][j];
                    heightMap[i][j] = heightMap[cur.first][cur.second];
                }

                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }

        return ans;
    }
};

int main()
{
    vector<vector<int>> heightMap{{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    cout << Solution().trapRainWater(heightMap) << endl;
    return 0;
}
