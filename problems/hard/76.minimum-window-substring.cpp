/*
 * 问题描述
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (28.49%)
 * Total Accepted:    181.1K
 * Total Submissions: 635.4K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
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
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();

        if(m < n) {
            return "";
        }

        static const int MAX_CHAR = 0xff;
        int s_cnt[MAX_CHAR+1] = {0};
        int t_cnt[MAX_CHAR+1] = {0};

        for(auto c: t) {
            t_cnt[c]++;
        }

        int ans = numeric_limits<int>::max();
        pair<int, int> res{m, 0};
        int len = 0;
        int start = 0;
        for(int i = 0; i < m; i++) {
            char c = s[i];
            s_cnt[c]++;

            if(s_cnt[c] == t_cnt[c]) {
                len += t_cnt[c];
            }
            
            if(len < n) {
                continue;
            }

            for(; s_cnt[s[start]] > t_cnt[s[start]]; start++) {
                s_cnt[s[start]]--;
            }

            int sub_len = i - start + 1;
            if(sub_len < ans) {
                res.first = start;
                res.second = i - start + 1;
                ans = sub_len;
            }

            s_cnt[s[start]]--;
            len -= t_cnt[s[start]];
            start++;

            if(start + n > m) {
                break;
            } 
        }

        return s.substr(res.first, res.second);
    }
};
