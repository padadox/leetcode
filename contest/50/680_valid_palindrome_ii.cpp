// 20181005 14:23
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
 *
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 *
 */
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        for(i = 0; i < s.size() / 2; i++) {
            if(s[i] != s[s.size()-1-i]) {
                break;
            }
        }

        if(i >= s.size() / 2) {
            return true;
        }
        
        int j = 0;
        for(; j <= (s.size() - 2 * i - 1) / 2; j++) {
            if(s[i+1+j] != s[s.size()-1-i-j]) {
                break;
            }
        }

        if(j >= (s.size() - 2 * i - 1) / 2) {
            return true;
        }

        j = 0;
        for(; j <= (s.size() - 2 * i - 1) / 2; j++) {
            if(s[i+j] != s[s.size()-2-i-j]) {
                break;
            }
        }

        if(j >= (s.size() - 2 * i - 1) / 2) {
            return true;
        }

        return false;
    }
};

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    cout << Solution().validPalindrome(s) << endl;
    return 0;
}
