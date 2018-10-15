/*
 *User Accepted: 422
User Tried: 641
Total Accepted: 439
Total Submissions: 1435
Difficulty: Medium
A sequence X_1, X_2, ..., X_n is fibonacci-like if:

n >= 3
X_i + X_{i+1} = X_{i+2} for all i + 2 <= n
Given a strictly increasing array A of positive integers forming a sequence, find the length of the longest fibonacci-like subsequence of A.  If one does not exist, return 0.

(Recall that a subsequence is derived from another sequence A by deleting any number of elements (including none) from A, without changing the order of the remaining elements.  For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].)

 

Example 1:

Input: [1,2,3,4,5,6,7,8]
Output: 5
Explanation:
The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: [1,3,7,11,12,14,18]
Output: 3
Explanation:
The longest subsequence that is fibonacci-like:
[1,11,12], [3,11,14] or [7,11,18].
 

Note:

3 <= A.length <= 1000
1 <= A[0] < A[1] < ... < A[A.length - 1] <= 10^9
(The time limit has been reduced by 50% for submissions in Java, C, and C++.)
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

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<vector<int> > length(A.size(), vector<int>(A.size(), 0));

        if(A.size() < 3) {
            return 0;
        }

        int m = 0;
        for(int i = 2; i < A.size(); ++i) {
            for(int j = i - 1; j > 0; j--) {
                int c = A[i] - A[j];
                if(c > A[j]) {
                    break;
                }

                auto it = lower_bound(A.begin(),  A.begin() + j, c);
                if(it != A.begin() + i && *it == c) {
                    int pre = it - A.begin();
                    length[i][j] = length[j][pre] + 1;
                    if(length[i][j] > m) {
                        m = length[i][j];
                    }
                }
            }
        }

        if(m > 0) {
            m += 2;
        }
        return m;
    }

    int search(vector<int>& v, int len, int sum) {

        return 0;
    }
};
