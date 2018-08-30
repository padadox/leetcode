
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

int gcd(int m, int n) {
    if(m == 0 || n == 0) {
        return 0;
    }

    while(1) {
        if(m > n) {
            m = m % n;
            if(m == 0) {
                return n;
            }
        }
        else {
            n = n % m;
            if(n == 0) {
                return m;
            }
        }
    }

    return 0;
}

class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
        int a = min(A, B);
        int b = max(A, B);

        int period = a * b / gcd(a, b);
        int n = period / a + period / b - 1;
        int cnt = N / n;
        int r = N % n;

        int low = 0;
        int high = period; 
        int ans = ((cnt % MOD) * period) % MOD;

        while(low <= high) {
            int middle = (low + high) / 2;
            int ca = middle / a;
            int cb = middle / b;
            int c = ca + cb;

            if(c == r) {
                int x = max(ca * a, cb * b);
                ans = (ans + x) % MOD;
                break;
            }

            if(c < r) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }

        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    cout << s.nthMagicalNumber(1, 2, 3) << endl;
    
    return 0;
}
