/*
 * 问题描述
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (31.72%)
 * Total Accepted:    124.7K
 * Total Submissions: 392.9K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
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
 * 方法1：
 * 对每个位置i，计算到i结束和从i开始的区间内收益最大值。迭代i，找出前后区间最大值的和的最大值。
 * 方法2：
 * The thinking is simple and is inspired by the best solution from Single Number II (I read through the discussion after I use DP).
Assume we only have 0 money at first;
4 Variables to maintain some interested 'ceilings' so far:
The maximum of if we've just buy 1st stock, if we've just sold 1nd stock, if we've just buy 2nd stock, if we've just sold 2nd stock.
Very simple code too and work well. I have to say the logic is simple than those in Single Number II.

public class Solution {
    public int maxProfit(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for(int i:prices){                              // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = Math.max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = Math.max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2; ///Since release1 is initiated as 0, so release2 will always higher than release1.
    }
}
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) {
            return 0;
        }

        vector<int> left(prices.size(), 0);
        vector<int> right(prices.size(), 0);

        int mi = prices[0];
        int ma = prices[0];
        int res = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > ma) {
                ma = prices[i];
            }
            else if(prices[i] < mi) {
                mi = prices[i];
                ma = mi;
            }

            res = max(res, ma - mi);
            left[i] = res;
        }

        mi = prices.back();
        ma = prices.back();
        res = 0;
        for(int i = prices.size()-2; i >= 0; i--) {
            if(prices[i] > ma) {
                ma = prices[i];
                mi = ma;
            }
            else if(prices[i] < mi) {
                mi = prices[i];
            }

            res = max(res, ma - mi);
            right[i] = res;
        }

        int ans = 0;
        for(int i = 0; i < prices.size(); i++) {
            ans = max(left[i] + right[i], ans);
        }

        return ans;
    }
};
