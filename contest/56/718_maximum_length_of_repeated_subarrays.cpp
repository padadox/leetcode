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
 *718. Maximum Length of Repeated Subarray
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
 *
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        return max(find(A, B), find(B, A));
    }

    int find(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int ans = 0;

        for(int j = 0; j < n - ans; j++) {
            int cnt = 0;
            for(int i = 0; i < m; ++i) {
                if(j + i >= n) {
                    break;
                }

                if(A[i] == B[j+i]) {
                    cnt++;
                    continue;
                }

                if(cnt > ans) {
                    ans = cnt;
                }
                cnt = 0;
            }
            if(cnt > ans) {
                ans = cnt;
            }
        }

        return ans;
    }
};

