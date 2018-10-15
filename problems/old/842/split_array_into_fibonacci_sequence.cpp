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

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/*
Given a string S of digits, such as S = "123456579", we can split it into a Fibonacci-like sequence [123, 456, 579].

Formally, a Fibonacci-like sequence is a list F of non-negative integers such that:

0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer type);
F.length >= 3;
and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
Also, note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number 0 itself.

Return any Fibonacci-like sequence split from S, or return [] if it cannot be done.

Example 1:

Input: "123456579"
Output: [123,456,579]
Example 2:

Input: "11235813"
Output: [1,1,2,3,5,8,13]
Example 3:

Input: "112358130"
Output: []
Explanation: The task is impossible.
Example 4:

Input: "0123"
Output: []
Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
Example 5:

Input: "1101111"
Output: [110, 1, 111]
Explanation: The output [11, 0, 11, 11] would also be accepted.
Note:

1 <= S.length <= 200
S contains only digits.
*/

class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        vector<int> ans;
        ans.reserve(s.size());
        bool found = false;
        int n = s.size();

        for(int i = 1; i <= n / 2 && i <= 10; i++) {
            if(i > 1 && s[0] == '0') {
                break;
            }

            ll first_orig = atoll(s.substr(0, i).c_str());
            if(first_orig > numeric_limits<int>::max()) {
                break;
            }
            ans.push_back(first_orig);
            for(int j = 1; i + j < n && j <= 10; j++) {
                if(j > 1 && s[i] == '0') {
                    break;
                }

                int len = max(i, j);
                if(i + j + len > n) {
                    break;
                }

                ll first = first_orig;
                ll second = atoll(s.substr(i, j).c_str());
                if(second > numeric_limits<int>::max()) {
                    break;
                }

                ans.resize(1);
                ans.push_back(second);

                int b = i + j;
                for(;b < n;) {
                    if(b + len > n) {
                        break;
                    }

                    if(first != 0 && s[b] == '0') {
                        break;
                    }

                    ll third = atoll(s.substr(b, len).c_str());
                    if(third != first + second) {
                        len++;
                        if(b + len <= n && len <= 10) {
                            third = third * 10 + s[b+len-1] - '0';
                            if(third != first + second) {
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }

                    if(third > numeric_limits<int>::max()) {
                        break;
                    }

                    ans.push_back(third);
                    b += len;
                    first = second;
                    second = third;
                }

                if(b >= n) {
                    found = true;
                    break;
                }
            }

            if(found) {
                break;
            }

            ans.resize(0);
        }

        return ans;
    }
};


int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    vector<int> result = Solution().splitIntoFibonacci(s);
    for(auto x: result) {
        cout << x << " ";
    }

    cout << endl;
    
    return 0;
}
