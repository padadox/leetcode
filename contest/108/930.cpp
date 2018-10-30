// 20181029 20:40
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


/**
 * 问题描述
 *930. Binary Subarrays With Sum
Virtual User Accepted: 24
Virtual User Tried: 36
Virtual Total Accepted: 24
Virtual Total Submissions: 36
Difficulty: Medium
In an array A of 0s and 1s, how many non-empty subarrays have sum S?

 

Example 1:

Input: A = [1,0,1,0,1], S = 2
Output: 4
Explanation: 
The 4 subarrays are bolded below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
 

Note:

A.length <= 30000
0 <= S <= A.length
A[i] is either 0 or 1.
 */


/**
 * 解决方案
 *
 */


static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int> cnt;
        cnt.reserve(A.size()+1);
        int zero = 1;
        for(auto x: A) {
            if(!x) {
                zero++;
                continue;
            }

            cnt.push_back(zero);
            zero = 1;
        }

        cnt.push_back(zero);

        int ans = 0;
        if(S > 0) {
            for(int i = 0; i < cnt.size() - S; i++) {
                ans += cnt[i] * cnt[i + S];
            }
        }
        else {
            for(int i = 0; i < cnt.size(); i++) {
                ans += cnt[i] * (cnt[i]-1) / 2;
            }
        }

        return ans;
    }
};
