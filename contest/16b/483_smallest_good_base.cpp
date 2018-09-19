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
 *483. Smallest Good Base
For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.

Now given a string representing n, you should return the smallest good base of n in string format. 

Example 1:
Input: "13"
Output: "3"
Explanation: 13 base 3 is 111.

Example 2:
Input: "4681"
Output: "8"
Explanation: 4681 base 8 is 11111.

Example 3:
Input: "1000000000000000000"
Output: "999999999999999999"
Explanation: 1000000000000000000 base 999999999999999999 is 11.
Note:
The range of n is [3, 10^18].
The string representing n is always valid and will not have leading zeros.
 *
 */

class Solution {
public:
    string smallestGoodBase(string n) {
        ll num = atoll(n.c_str());

        ll ans = num - 1;

        int cnt = 1;
        ll m = num;
        while(m >>= 1) {
            cnt++;
        }

        for(int i = cnt; i > 2; i--) {
            ll x = find(num, i);
            if(x != -1) {
                ans = x;
                break;
            }
        }

        char buf[128];
        sprintf(buf, "%lld", ans);

        return string(buf);
    }

    ll find(ll num, int n) {
        ll high = ll(pow(num, 1./(n-1)));
        ll low = ll(pow(num, 1./n));
        while(low <= high) {
            ll middle = (high + low) >> 1;

            ll res = 0;
            for(int i = 0; i < n; i++) {
                res *= middle;
                res += 1;
            }

            if(res == num) {
                return middle;
            }

            if(res > num) {
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return -1;
    }
};

int main(int argc, const char *argv[])
{
    string input;
    cin >> input;
    cout << Solution().smallestGoodBase(input);
    return 0;
}
