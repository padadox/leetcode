// 20181012 20:15
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
#include <cctype>
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
 *
 *A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.
 *
 */

/*
 * 方法:
 * 该题关键在梳理清楚几种修复操作的关系，即哪些修复可以合并为一个操作。
 */

class Solution {
    // 下面几个常量同逻辑相关，不能简单的改数值即支持新的配置。
    static const int MIN_LEN = 6;
    static const int MAX_LEN = 20;
    static const int MIN_INVALID_REP_LEN = 3;
public:
    int strongPasswordChecker(string s) {
        vector<int> repeat_len;
        int need_upper = 1;
        int need_lower = 1;
        int need_digit = 1;
        int repeat_repair_op = 0;

        char pre = '\0';
        char cnt = 0;
        for(auto x: s) {
            if(islower(x)) {
                need_lower = 0;
            }
            else if(isupper(x)) {
                need_upper = 0;
            }
            else if(isdigit(x)) {
                need_digit = 0;
            }

            if(x == pre) {
                cnt++;
            }
            else {
                if(cnt >= MIN_INVALID_REP_LEN) {
                    repeat_len.push_back(cnt);
                    repeat_repair_op += cnt / MIN_INVALID_REP_LEN;
                }

                cnt = 1;
                pre = x;
            }
        }

        if(cnt >= MIN_INVALID_REP_LEN) {
            repeat_len.push_back(cnt);
            repeat_repair_op += cnt / MIN_INVALID_REP_LEN;
        }

        int need_cnt = need_upper + need_lower + need_digit;
        int ans = need_cnt;
        if(s.size() < MIN_LEN) {
            ans = max(need_cnt, MIN_LEN - (int)s.size());
        }

        if(s.size() <= MAX_LEN) {
            static_assert(MIN_LEN <= 2 * MIN_INVALID_REP_LEN);
            ans = max(repeat_repair_op, ans);
            return ans;
        }

        auto func = [](int a, int b) -> bool {
            return (a % MIN_INVALID_REP_LEN) > (b % MIN_INVALID_REP_LEN);
        };

        priority_queue<int, vector<int>, decltype(func)> q(repeat_len.begin(), repeat_len.end(), func);
        int d = s.size() - MAX_LEN;
        ans += d;
        while(!q.empty()) {
            int a = q.top();
            q.pop();

            /* 
            if(a % MIN_INVALID_REP_LEN == 0) {
                repeat_repair_op--;
            }
            a--;
            d--;
            */

            int x = (a % MIN_INVALID_REP_LEN) + 1;
            if(d < x) {
                break;
            }

            a -= x;
            d -= x;
            repeat_repair_op--;

            if(a >= MIN_INVALID_REP_LEN) {
                q.push(a);
            }
        }

        ans += max(repeat_repair_op - need_cnt, 0);

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    cout << Solution().strongPasswordChecker(s) << endl;
    return 0;
}
