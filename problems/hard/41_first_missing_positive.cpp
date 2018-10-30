// 20181019 18:21
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
 *Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
 */


/**
 * 解决方案
 * 利用目标值不会大于数组大小的特点，使用已有空间存储，对合法的nums[i](大于0，小于等于数组大小n), 令nums[nums[i]-1] = nums[i]; 然后遍历，找到第一个不符合nums[j-1] = j的j值。
 *
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i <= n; i++) {
            int j = nums[i-1];
            while(true) {
                if(j < 1 || j > n) {
                    break;
                }
                if(nums[j-1] == j) {
                    break;
                }

                int m = nums[j-1];
                nums[j-1] = j;
                j = m;
            }
        }

        int ans = n + 1;
        for(int i = 1; i <= n; i++) {
            if(nums[i-1] != i) {
                ans = i;
                break;
            }
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
        cout << Solution().firstMissingPositive(nums) << endl;
    }
    
    return 0;
}
