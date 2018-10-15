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
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)

 */


class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num < 2) {
            return false;
        }

        int sum = 1;
        int m = int(sqrt(num));
        for(int i = 2; i < m; ++i) {
            if (num % i != 0) {
                continue;
            }

            int j = num / i;

            sum += i + j;
        }

        if(m > 1 && num % m == 0) {
            int j = num / m;
            sum += m;
            if(j != m) {
                sum += j;
            }
        }

        return sum == num;
    }
};

int main(int argc, const char *argv[])
{
    cout << Solution().checkPerfectNumber(6);
    return 0;
}
