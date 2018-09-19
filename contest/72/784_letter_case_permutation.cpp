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
 *Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
 */


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if(S.empty()) {
            return vector<string>(1, "");
        }


        vector<string> ans;
        vector<int> flag;
        flag.resize(S.size()+1, 0);
        string s;
        int i = 0;
        while(i >= 0) {
            if(i == S.size()) {
                ans.push_back(s);
                i--;
                s.pop_back();
                continue;
            }

            if('0' <= S[i] && '9' >= S[i]) {
                if(flag[i] == 0) {
                    s.push_back(S[i]);
                    flag[i] = 2;
                    flag[i+1] = 0;
                    i++;
                }
                else {
                    i--;
                    s.pop_back();
                }

                continue;
            }

            if(flag[i] == 0) {
                s.push_back(S[i]);
                flag[i] = 1;
                flag[i+1] = 0;
                i++;
            }
            else if(flag[i] == 1) {
                s.push_back(S[i] ^ 0x20);
                flag[i] = 2;
                flag[i+1] = 0;
                i++;
            }
            else {
                i--;
                s.pop_back();
            }
        }

        return ans;
    }


};
