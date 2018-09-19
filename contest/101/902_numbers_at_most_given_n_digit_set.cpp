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
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int n = N;
        vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }

        vector<int> d;
        for(auto &x: D) {
            d.push_back(atoi(x.c_str()));
        }

        ll ans = 0;
        vector<ll> mul(digits.size() + 1);
        mul[0] = 1;
        for(int i = 1; i < digits.size(); ++i) {
            mul[i] = mul[i-1] * d.size();
            ans += mul[i];
        }

        for(int i = digits.size() - 1; i >= 0; i--) {
            int cur = digits[i];
            int cnt = 0;

            auto pos = lower_bound(d.begin(), d.end(), cur);

            if(pos == d.end()) {
                cnt = d.size();
            }
            else {
                cnt = pos - d.begin();
            }

            ans += cnt * mul[i];

            if(*pos != cur) {
                break;
            }
            else {
                if(i == 0) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<string> A{"7"};
    int n = 8;

    cout << Solution().atMostNGivenDigitSet(A, n);
    
    return 0;
}
