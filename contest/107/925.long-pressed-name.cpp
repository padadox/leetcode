/*
 * 问题描述
 * [961] Long Pressed Name
 *
 * https://leetcode.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (45.15%)
 * Total Accepted:    5.2K
 * Total Submissions: 11.6K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a
 * character c, the key might get long pressed, and the character will be typed
 * 1 or more times.
 * 
 * You examine the typed characters of the keyboard.  Return True if it is
 * possible that it was your friends name, with some characters (possibly none)
 * being long pressed.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: name = "alex", typed = "aaleex"
 * Output: true
 * Explanation: 'a' and 'e' in 'alex' were long pressed.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: name = "saeed", typed = "ssaaedd"
 * Output: false
 * Explanation: 'e' must have been pressed twice, but it wasn't in the typed
 * output.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: name = "leelee", typed = "lleeelee"
 * Output: true
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: name = "laiden", typed = "laiden"
 * Output: true
 * Explanation: It's not necessary to long press any character.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * name.length <= 1000
 * typed.length <= 1000
 * The characters of name and typed are lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
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
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        for(; i < name.size(); ) {
            char c = name[i];
            int cnt_name = 1;
            for(++i; i < name.size() && c == name[i]; ++i) {
                cnt_name++;
            }

            int cnt_typed = 0;
            for(; j < typed.size() && c == typed[j]; j++) {
                cnt_typed++;
            }

            if(cnt_name > cnt_typed) {
                return false;
            } 
        }

        if(j >= typed.size()) {
            return true;
        }

        return false;
    }
};
