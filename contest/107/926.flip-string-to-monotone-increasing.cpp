/*
 * 问题描述
 * [962] Flip String to Monotone Increasing
 *
 * https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
 *
 * algorithms
 * Medium (39.57%)
 * Total Accepted:    3.9K
 * Total Submissions: 9.2K
 * Testcase Example:  '"00110"'
 *
 * A string of '0's and '1's is monotone increasing if it consists of some
 * number of '0's (possibly 0), followed by some number of '1's (also possibly
 * 0.)
 * 
 * We are given a string S of '0's and '1's, and we may flip any '0' to a '1'
 * or a '1' to a '0'.
 * 
 * Return the minimum number of flips to make S monotone increasing.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "00110"
 * Output: 1
 * Explanation: We flip the last digit to get 00111.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "010110"
 * Output: 2
 * Explanation: We flip to get 011111, or alternatively 000111.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "00011000"
 * Output: 2
 * Explanation: We flip to get 00000000.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 20000
 * S only consists of '0' and '1' characters.
 * 
 * 
 * 
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
 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int op_0 = 0;
        int op_1 = 0;

        for(auto c: S) {
            if(c == '1') {
                op_1 = min(op_0, op_1);
                op_0++;
            }
            else {
                op_1++;
            }
        }

        return min(op_0, op_1);
    }
};
