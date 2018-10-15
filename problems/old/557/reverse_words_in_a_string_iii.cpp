// 20181012 19:40
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
 *
 *Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
 *
 */

class Solution {
    public:
        string reverseWords(string s) {
            auto start = s.begin();
            for(auto it = s.begin(); it != s.end(); ++it) {
                if(*it != ' ') {
                    continue;
                }

                reverse(start, it);
                start = it + 1;
            }
            reverse(start, s.end());
            return s;
        }
};

/*
class Solution {
public:
    string reverseWords(string s) {
        string ret;
        ret.reserve(s.size());
        size_t start = 0;
        for(size_t i = 0; i <= s.size(); i++) {
            if(i == s.size() || s[i] == ' ') {
                int j = 1;
                for(; start + j <= i; ++j) {
                    ret.push_back(s[i-j]);
                }

                if(i < s.size()) {
                    ret.push_back(s[i]);
                    start = i + 1;
                }
            }
        }

        cout << ret.size() << endl;
        return ret;
    }
};
*/

int main(int argc, const char *argv[])
{
    string s = "123 234";
    cout << Solution().reverseWords(s) << endl;
    
    return 0;
}
