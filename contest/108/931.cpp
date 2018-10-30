// 20181029 21:08
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
 *931. Minimum Falling Path Sum
Virtual User Accepted: 362
Virtual User Tried: 406
Virtual Total Accepted: 362
Virtual Total Submissions: 406
Difficulty: Medium
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
The falling path with the smallest sum is [1,4,7], so the answer is 12.

 

Note:

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
 */


/**
 * 解决方案
 *
 */


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> min_sum(A.size(), vector<int>(A[0].size(), 0));

        for(int i = 0; i < A[0].size(); i++) {
            min_sum[0][i] = A[0][i];
        }

        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                int tmp = min_sum[i-1][j];
                if(j > 0) {
                    tmp = min(tmp, min_sum[i-1][j-1]);
                }

                if(j < A[i].size() - 1) {
                    tmp = min(tmp, min_sum[i-1][j+1]);
                }

                min_sum[i][j] = A[i][j] + tmp;
            }
        }

        return *min_element(min_sum[A.size()-1].begin(), min_sum[A.size()-1].end());
    }
};
static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


