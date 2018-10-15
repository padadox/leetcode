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

/**
 *Given an array A, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

 

Example 1:

Input: [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 

Note:

2 <= A.length <= 30000
0 <= A[i] <= 10^6
It is guaranteed there is at least one way to partition A as described.
 */


/**
 *  方法：
 *      1、从前向后统计到达每个位置的最大值；
 *      2、从后向前统计到达每个位置的最小1值；
 *      3、遍历，直到某个位置的最大值，小于下一位置的最小值。
 *
 */

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> min(A.size(), numeric_limits<int>::max());
        vector<int> max(A.size(), numeric_limits<int>::min());

        int mi = numeric_limits<int>::max();
        for(int i = A.size()-1; i >= 0; i--) {
            if(A[i] < mi) {
                mi = A[i];
            }

            min[i] = mi;
        }

        int ma = numeric_limits<int>::min();
        for(int i = 0; i < A.size(); i++) {
            if(A[i] > ma) {
                ma = A[i];
            }

            max[i] = ma;
        }

        for(int i = 0; i < A.size(); i++) {
            if(max[i] <= min[i+1]) {
                return i+1;
            }
        }

        return 0;
    }
};
