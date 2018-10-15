// 20181001 01:41
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
 *In a string S of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.

 

Example 1:

Input: "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
Example 2:

Input: "abc"
Output: []
Explanation: We have "a","b" and "c" but no large group.
Example 3:

Input: "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
 

Note:  1 <= S.length <= 1000
 *
 */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char pre = '\0';
        int start = -1;
        int cnt = 0;
        vector<vector<int>> ans;
        for(int i = 0; i < S.size(); i++) {
            char c = S[i];
            if(c == pre) {
                cnt++;
                continue;
            }

            if(cnt >= 3) {
                vector<int> one;
                one.push_back(start);
                one.push_back(i-1);
                ans.push_back(one);
            }

            pre = c;
            cnt = 1;
            start = i;
        }

        return ans;
    }
};
