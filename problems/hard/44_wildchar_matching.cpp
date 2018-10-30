// 20181019 19:16
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
 *Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
 */


/**
 * 解决方案
 *
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> match(p.size()+1, vector<bool>(s.size()+1, false));
        match[0][0] = true;
        for(int i = 1; i <= static_cast<int>(p.size()); i++) {
            for(int j = 0; j <= static_cast<int>(s.size()); j++) {
                if(p[i-1] == '*') {
                    match[i][j] = ((j == 0) && match[i-1][j]) || ((j > 0) &&  (match[i][j-1] || match[i-1][j-1] || match[i-1][j]));
                }
                else {
                    match[i][j] = (j > 0) && (p[i-1] == '?' || p[i-1] == s[j-1]) && match[i-1][j-1];
                }
            }
        }

        return match[p.size()][s.size()];
    }
};

int main(int argc, const char *argv[])
{
   while(true) {
       string s;
       cin >> s;
       if(s == "q") {
           break;
       }

       string p;
       cin >> p;
       cout << Solution().isMatch(s, p) << endl;
   }
    return 0;
}
