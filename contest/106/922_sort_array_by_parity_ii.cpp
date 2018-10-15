// 20181014 23:20
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
 *Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000
 */

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> ans;
        ans.resize(A.size());
        int i = 0;
        int j = 1;
        for(auto x: A) {
            if(x & 1) {
                ans[j] = x;
                j += 2;
            }
            else {
                ans[i] = x;
                i += 2;
            }
        }

        return ans;
    }
};


