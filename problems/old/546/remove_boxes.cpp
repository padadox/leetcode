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
 *
 Given several boxes with different colors represented by different positive numbers. 
 You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
 Find the maximum points you can get.

 Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
*/

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        vector<pair<int, int>> pairs;
        pairs.reserve(boxes.size());

        int pre = 0;
        int cnt = 0;
        for(auto x: boxes) {
            if(x != pre) {
                if(cnt != 0) {
                    pairs.push_back(make_pair(pre, cnt));
                }

                pre = x;
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        pairs.push_back(make_pair(pre, cnt));

        vector<vector<int>> result(pairs.size(), vector<int>(pairs.size()+1, 0));

        for(int n = 1; n <= pairs.size(); n++) {
            for(int i = 0; i+n-1 < pairs.size(); i++) {
                auto &x = pairs[i+n-1];
                result[i][n] = combine_result(pairs, result, i, i+n-1, x.first, x.second);
            }
        }

        return result[0][pairs.size()];
    }

    int combine_result(const vector<pair<int, int>> &pairs, const vector<vector<int>>& result, int s, int e, int v, int c) {
        int m = c * c + result[s][e-s];
        for(int j = e-2; j >= s; j--) {
            auto &x = pairs[j];
            if(x.first != v) {
                continue;
            }

            // 部分子问题仍然重复计算，可以考虑使用map缓存结果
            int cur = combine_result(pairs, result, s, j, v, c + x.second) + result[j+1][e-j-1];
            if(cur > m) {
                m = cur;
            }
        }

        return m;
    }

};

int main(int argc, const char *argv[])
{
    vector<int> v {3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7};

    cout << Solution().removeBoxes(v);
    
    return 0;
}
