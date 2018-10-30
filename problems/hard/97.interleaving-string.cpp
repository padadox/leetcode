/*
 * 问题描述
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (26.24%)
 * Total Accepted:    94.4K
 * Total Submissions: 359.6K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
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
 * 深度优先搜索+DP
 * 纯DP会有较多无效运算。
 */

class Solution {
    string s1;
    string s2;
    string s3;
    set<pair<int, int>> error_set;
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;

        return judge(0, 0);
    }

    bool judge(int i, int j) {
        if(error_set.find(make_pair(i, j)) != error_set.end())  {
            return false;
        }

        int b = i + j;
        int k = b;
        for(; k < s3.size(); k++) {
            bool match1 = false;
            bool match2 = false;

            if(i < s1.size() && s3[k] == s1[i]) {
                match1 = true;
            }

            if(j < s2.size() && s3[k] == s2[j]) {
                match2 = true;
            }

            if(!(match1 || match2)) {
                break;
            }

            if(match1 && match2) {
                if(judge(i+1, j)) {
                    return true;
                }

                if(judge(i, j+1)) {
                    return true;
                }
                break;
            }

            if(match1) {
                i++;
            }
            else {
                j++;
            }
        }

        if(i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }

        error_set.emplace(i, j);
        return false;
    }
};
