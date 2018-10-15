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
 *
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]
Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]
Example 3:

Input: A = [1,3,6], K = 3
Output: 3
Explanation: B = [4,6,3]
 

Note:

1 <= A.length <= 10000
0 <= A[i] <= 10000
0 <= K <= 10000
 *
 */


class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        if(A.size() <= 1) {
            return 0;
        }

        sort(A.begin(), A.end());

        int n = A.size();


        int ma = A[n-1];
        int mi = A[0];

        if((ma - mi) <= K || K == 0) {
            return ma - mi;
        }

        auto it = lower_bound(A.begin(), A.end(), (ma + mi + 1) / 2);
        auto pre = it - 1;

        auto up = it - 1;
        auto down = it;

        if((*it * 2) == (ma + mi)) {
            auto post = it + 1;
            for(; post != A.end(); post++) {
                if(*post != *it) {
                    break;
                }
            }

            if(*post - *it > *it - *pre) {
                up = post - 1;
                down = post;
            }
        }

        for(auto x = A.begin(); x != down; ++x) {
            *x += K;
        }

        for(auto x = down; x != A.end(); ++x) {
            *x -= K;
        }

        auto new_ma = *max_element(A.begin(), A.end());
        auto new_mi = *min_element(A.begin(), A.end());
        int ans = new_ma - new_mi;

        /*
           int high = max(*up + K, ma - K);
           int low = min(*down - K, mi + K);

           int ans = high - low;
       */
        if(ma - mi < ans) {
            ans = ma - mi;
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<int> A
{8038,9111,5458,8483,5052,9161,8368,2094,8366,9164,53,7222,9284,5059,4375,2667,2243,5329,3111,5678,5958,815,6841,1377,2752,8569,1483,9191,4675,6230,1169,9833,5366,502,1591,5113,2706,8515,3710,7272,1596,5114,3620,2911,8378,8012,4586,9610,8361,1646,2025,1323,5176,1832,7321,1900,1926,5518,8801,679,3368,2086,7486,575,9221,2993,421,1202,1845,9767,4533,1505,820,967,2811,5603,574,6920,5493,9490,9303,4648,281,2947,4117,2848,7395,930,1023,1439,8045,5161,2315,5705,7596,5854,1835,6591,2553,8628};
    int K = 4643;

    cout << Solution().smallestRangeII(A, K) << endl;
    
    return 0;
}
