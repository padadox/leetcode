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
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7
Example 2:

Input: 8
Output: 11
Example 3:

Input: 13
Output: 101
 

Note:

1 <= N <= 10^8
The answer is guaranteed to exist and be less than 2 * 10^8.
*/

class Solution {
public:
    int primePalindrome(int N) {
        int m = 2000;

        if(N <= 7) {
            int a[] = {2, 3, 5, 7};
            for(auto x: a) {
                if(x >= N) {
                    return x;
                }
            }
        }

        int d = 0;
        int n = N;
        while(n > 0) {
            n /= 10;
            d++;
        }

        d /= 2;
        d--;

        int c = 1;
        for(int i = 0; i < d; i++) {
            c *= 10;
        }
        for(int i = d; i <= 3; i++, c *= 10) {
            // even number of digits
            for(int m = c; m < c * 10; m++) {
                int f = 0;
                int r = reverse(m, f);
                int x = m * f + r;
                if(x < N) {
                    continue;
                }

                if(isPrime(x)) {
                    return x;
                }
            }

            for(int m = c; m < c * 10; m++) {
                // odd number of digits
                int f = 0;
                int r = reverse(m, f);
                int x = 0;
                for(int j = 0; j < 10; j++) {
                    x = m * 10;
                    x += j;
                    x *= f;
                    x += r;

                    if(x < N) {
                        continue;
                    }

                    if(isPrime(x)) {
                        return x;
                    }
                }
            }

        }

        return 0;
    }

    bool isPrime(int n) {
        auto m = int(sqrt(n));
        for(int i = 2; i <= m; i++) {
            if(n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int reverse(int n, int &f) {
        f = 1;
        int r = 0;
        while(n > 0) {
            int m = n % 10;
            n /= 10;
            r = r * 10 + m;
            f *= 10;
        }

        return r;
    }
};

int main(int argc, const char *argv[])
{
    int N = 0;
    cin >> N;
    cout << Solution().primePalindrome(N) << endl;
    return 0;
}
