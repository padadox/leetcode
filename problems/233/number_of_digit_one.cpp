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
 *Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

Example:

Input: 13
Output: 6 
Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 */

class Solution {
public:
    int countDigitOne(int n) {
        int mask = 1;
        int ans = 0;
        while(n > 0) {
            int c = (n / mask) % 10;
            int pre = n / mask / 10 + 1;
            int post = n % mask + 1;

            if(c <= 1) {
                ans += (pre - 1) * mask + c * post;
            }
            else {
                ans += pre * mask;
            }

            if(pre == 1) {
                break;
            }

            mask *= 10;
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    int x;
    cin >> x;
    cout << Solution().countDigitOne(x) << endl;
    return 0;
}
