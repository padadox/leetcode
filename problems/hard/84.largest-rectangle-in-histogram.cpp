/*
 * 问题描述
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (28.98%)
 * Total Accepted:    139.5K
 * Total Submissions: 481.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
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



static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/*
 * 解决方案
 * 对于每个height值，确定以该值为高矩形范围（即该值分别往左、往右为最小值的范围)。
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        auto f = [](auto b, auto e, auto vit) -> void {
            for(auto it = b; it != e; it++, vit++) {
                if(it == b) {
                    *vit = 1;
                    continue;
                }

                int pre = 1;
                while((pre <= (it - b)) && (*it <= *(it - pre))) {
                    pre += *(vit - pre);
                }

                *vit = pre;
            }
        };

        f(heights.begin(), heights.end(), left.begin());
        f(heights.rbegin(), heights.rend(), right.rbegin());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(heights[i] * (left[i] + right[i] - 1), ans);
        }

        return ans;
    }
};

/*
int main(int argc, const char *argv[])
{
    vector<int> v{2, 1, 5, 6, 2, 3};
    cout << Solution().largestRectangleArea(v) << endl;
    return 0;
}
*/
