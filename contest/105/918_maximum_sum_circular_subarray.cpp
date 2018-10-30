// 20181016 18:40
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



/**
 *Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
 */

/*
 * 方法1:
 * 类似与862，计算到每个位置结束的subarray的值
 * 方法2:
 * I guess you know how to solve max subarray sum (without circular).
If not, you can have a reference here: 53. Maximum Subarray

So there are two case.

The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.
Here is a diagram by @motorix:
|       |Max SubArray|      |
|                 |Max SubAr!ray|                   |   ! is the last element
|Max SubArray|Min SubArray|Max SubArray|

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)

One** corner case** to pay attention:
If all number are negative,
return the maximum one,
(which equals to the max subarray sum)
 *
 *
 */

/*
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.empty()) {
            return 0;
        }

        int n = A.size();
        A.reserve(A.size() * 2);
        A.insert(A.end(), A.begin(), A.end());

        vector<int> sum;
        sum.resize(A.size() + 1, 0);
        for(int i = 0; i < A.size(); i++) {
            sum[i+1] = sum[i] + A[i];
        }

        int ans = numeric_limits<int>::min();
        deque<int> d;

        for (int i = 0; i < sum.size(); i++) {
            if(!d.empty()) {
                if(d.front() > n) {
                    break;
                }

                while(i - d.front() > n) {
                    d.pop_front();
                }

                ans = max(ans, sum[i] - sum[d.front()]);
            } 

            while (d.size() > 0 && sum[i] <= sum[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);
        }

        return ans;
    }
};
*/
class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& A) {
            int total = 0, maxSum = -30000, curMax = 0, minSum = 30000, curMin = 0;
            for (int a : A) {
                curMax = max(curMax + a, a);
                maxSum = max(maxSum, curMax);
                curMin = min(curMin + a, a);
                minSum = min(minSum, curMin);
                total += a;
            }
            return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
        }
};

#include "../../utils/utils.hxx"

int main(int argc, const char *argv[])
{
    while(true) {
        string s;
        cin >> s;
        if(s == "q") {
            break;
        }
        vector<int> nums = stringToIntegerVector(s);
        cout << Solution().maxSubarraySumCircular(nums) << endl;
    }
    
    return 0;
}
