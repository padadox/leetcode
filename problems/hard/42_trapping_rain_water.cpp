// 20181019 19:02
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
 *Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 */


/**
 * 解决方案
 *
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);

        int l = 0;
        int r = 0;
        for(int i = 0; i < n; i++) {
            left_max[i] = l;
            right_max[n-1-i] = r;
            l = max(l, height[i]);
            r = max(r, height[n-1-i]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += max(0, min(left_max[i], right_max[i]) - height[i]);
        }

        return ans;
    }
};

#include "../../utils/utils.hxx"

int main(int argc, const char *argv[])
{
    while(true) {
        string s;
        cin >> s;
        if(s == "q") {
            break;
        }

        vector<int> nums = stringToIntegerVector(s);
        cout << Solution().trap(nums) << endl;
    }
    return 0;
}
