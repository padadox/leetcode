// 20181017 23:55
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
 *Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */

/**
 * 解决方案
 * 方法1:
 * 栈st, 保存每个确定的连续合法串的长度，以及未匹配的'('个数。在每个合法的'('处，检查是否当前匹配是否和栈顶串合并（当前未匹配'('个数<=栈顶未匹配个数。）,如果可以合并，栈顶元素出栈，继续检查下一元素，直到栈空或无法合并为止。当前元素入栈。遇到不合法')'，重置栈。
 * 方法2:
 * 使用栈进行括号匹配。遇到'('入栈当前索引，遇到')', 如果栈顶索引对应'(', 则栈顶元素出栈，否则入栈当前索引。最后，栈中保存了所有不匹配的n个元素索引，将字符串分割为n+1段（包括开头和结尾）。
 *
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int left_cnt = 0;
        stack<pair<int, int>> st;
        for(auto x: s) {
            if(x == '(') {
                left_cnt++;
                continue;
            }

            if(left_cnt <= 0) {
                st = stack<pair<int, int>>();
                continue;
            }

            left_cnt--;
            int match = 2;
            while(!st.empty()) {
                auto x = st.top();
                if(x.first < left_cnt) {
                    break;
                }

                match += x.second;
                st.pop();
            }

            st.emplace(left_cnt, match);
            ans = max(ans, match);
        }

        return ans;
    }
};

/*
 *
 class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        //invalid positions
        stack<int> pos;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') pos.push(i);
            else {
                if(pos.empty()) pos.push(i);
                else {
                    if(s[pos.top()] == '(') pos.pop();
                    else pos.push(i);
                }
            }
        }
        
        int res = 0;
        if(pos.empty()) res = len;
        else {
            int tail = len;
            while(!pos.empty()) {
                //cout << pos.top() << endl;
                int head = pos.top();
                pos.pop();
                res = max(res, tail - head - 1);
                tail = head;
            }
            res = max(res, tail);
        }
        return res;
    }
};*
 *
 */


int main(int argc, const char *argv[])
{
    while(true) {
        string s;
        cin >> s;
        if(s == "q") {
            break;
        }
        cout << Solution().longestValidParentheses(s) << endl;
    }
    return 0;
}
