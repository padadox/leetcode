// 20181010 10:45
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
 *
 *You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
 *
 */

/**
 * 方法：
 * 动态规划。
 * 先考虑最后一个和第一个不认为相邻的情况下，目标值。
 * 分别计算从第一个开始，到倒数第二个结束的目标值M1，和从第二个开始，到倒数第三个结束的目标值M2，
 * 最后一个元素X, 结果为max(M2+X, M1)
 * M1和M2的计算有重复，如果有标记记录计算M2时第一个元素是否使用，可以减小计算量。
 */


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        int first1 = 0;
        int second1 = 0;

        int first2 = 0;
        int second2 = 0;

        calc(nums, 0, first1, second1);
        calc(nums, 1, first2, second2);

        return max(first2 + nums.back(), second1);
    }

    void calc(vector<int>& nums, int start, int &first, int &second) {
        first = 0;
        second = 0;

        for(int i = start; i < nums.size()-1; i++) {
            int cur = first + nums[i];
           first = second;
           second = max(first, cur);
        }
    }
};

int main(int argc, const char *argv[])
{
    vector<int> nums
    {1, 2, 3, 1};
    cout << Solution().rob(nums) << endl;
    return 0;
}
