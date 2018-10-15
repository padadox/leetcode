// 20181005 16:13
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
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].
 *
 */


/**
 * 方法1：
 * 遍历，遇到'(', 增加其个数, 遇到'*'， 如果')'个数大于0，减小‘（’个数，否则，增加'*'个数，遇到')'优先消去'('的个数，不足时，消去'*'的个数，仍不足则非法；最后'('个数应为0；
 *
 * 方法2：
 * 正向遍历，'('和'*'的个数和应在每个')'大于')'的个数；反向，')'和'*'的个数和应在每个'('位置大于'('个数。
 *
 */

class Solution {
public:
    bool checkValidString(string s) {
        int left_cnt = 0;
        int right_cnt = 0;
        for(auto x: s) {
            if(x == '(' || x == '*') {
                left_cnt++;
                continue;
            }

            right_cnt++;
            if(left_cnt < right_cnt) {
                return false;
            }
        }

        left_cnt = 0;
        right_cnt = 0;
        for(auto it = s.rbegin(); it != s.rend(); it++) {
            if(*it == ')' || *it == '*') {
                right_cnt++;
                continue;
            }

            left_cnt++;
            if(right_cnt < left_cnt) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    cout << Solution().checkValidString(s) << endl;
    return 0;
}
