// 20181015 19:03
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
 *10. Regular Expression Matching
DescriptionHintsSubmissionsDiscussSolution
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
 */


/*
 * 方法1：
 *  广度优先搜索；
 * 方法2：
 *  深度优先搜索；
 * 方法3:
 *  DP, 判断s, p每个位置组合是否匹配。
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        int m = s.size(), n = p.size();
        vector< vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        for(int i = 0; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j - 2] ||
                              (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else {
                    dp[i][j] = (i > 0  && (s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1]);
                }
            }
        
        return dp[m][n];
    }
};
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        using t = tuple<int, int, char, bool>;  // <s_pos, p_pos, char, once>
        queue<t> q;
        q.emplace(-1, -1, '\0', true);
        bool match = false;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            int i, j, m;
            char c;
            tie(i, j, c, m) = x;

            if(i >= (int)s.size()-1) {
                if(j >= (int)p.size()-1) {
                    match = true;
                    break;
                }
            }

            if(i+1 < s.size() && !m && (c == s[i+1] || c == '.')) {
                q.emplace(i+1, j, c, m);
            }

            if(j + 1 >= p.size()) {
                continue;
            }

            j++;
            char next_p = p[j];
            bool limited = true;
            if(j+1 < p.size() && p[j+1] == '*') {
                j++;
                limited = false;
            }

            if(!limited) {
                q.emplace(i, j, next_p, true);  // '*' match none
            }

            if(i+1 < s.size() && next_p == '.' || next_p == s[i+1]) {
                q.emplace(i+1, j, next_p, limited);
            }
        }

        return match;
    }
};
*/


int main(int argc, const char *argv[])
{
    while(1) {
        string s;
        string p;
        cin >> s;
        cin >> p;
        cout << Solution().isMatch(s, p) << endl;
    }
    return 0;
}
