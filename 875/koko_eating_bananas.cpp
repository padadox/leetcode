/*
 *Virtual User Accepted: 244
Virtual User Tried: 306
Virtual Total Accepted: 244
Virtual Total Submissions: 306
Difficulty: Medium
Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.

Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

Return the minimum integer K such that she can eat all the bananas within H hours.

 

Example 1:

Input: piles = [3,6,7,11], H = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], H = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], H = 6
Output: 23
 

Note:

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using LL = long long;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        LL sum = 0;
        int m = 0;
        for(auto a: piles) {
            sum += a;
            if(a > m) {
                m = a;
            }
        }

        if((size_t)H == piles.size()) {
            return m;
        }

        int high = min((int)(sum / (H - piles.size()) + 1), m);
        int low = max((int)(sum / H), 1);

        while (low < high) {
            int middle = (low + high) / 2;
            int cnt = 0;
            for(auto a: piles) {
                cnt += (a + middle - 1) / middle;
            }

            if(cnt <= H) {
                high = middle;
            }
            else {
                low = middle + 1;
            }
        }

        return high;
    }
};
