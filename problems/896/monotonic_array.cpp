/*
 *An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
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
    bool isMonotonic(vector<int>& A) {
        if(A.empty()) {
            return true;
        }

        /*
        if(A.size() <= 1) {
            return true;
        }
        */

        int flag = A.back() - A.front();
        
        if(flag >= 0) {
            for(size_t i = 0; i + 1 < A.size(); i++) {
                if(A[i] > A[i+1]) {
                    return false;
                }
            }

            return true;
        }
        else {
            for(size_t i = 0; i + 1 < A.size(); i++) {
                if(A[i] < A[i+1]) {
                    return false;
                }
            }

            return true;
        }
    }
};
