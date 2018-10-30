// 20181022 01:01
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
 *Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
 */


/**
 * 解决方案
 *
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) {
            return 0;
        }

        int pre = 0;
        int m = nums[0];
        int n = static_cast<int>(nums.size()) - 1;
        int ans = 1;
        while(m < n) {
            int tmp = m;
            for(int i = m; i > pre && m < n; i--) {
                m = max(m, i + nums[i]);
            }

            pre = tmp;
            ans += 1;
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
        cout << Solution().jump(nums) << endl;
    }
    return 0;
}
