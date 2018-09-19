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
    if(n == 0) {
        return m;
    }

    return gcd(n, m % n);
}

class Solution {
public:
    int p_;
    int mirrorReflection(int p, int q) {
        if(q == 0) {
            return 0;
        }

        int lcm = p * q / gcd(p, q);
        p = lcm / p;
        q = lcm / q;

        if((q & 1) == 0) {
            return 2;
        }

        if((p & 1) == 0) {
            return 0;
        }

        return 1;
    }

};

int main(int argc, const char *argv[])
{
    int p = 0;
    int q = 0;

    cin >> p;
    cin >> q;

    Solution s;
    cout << s.mirrorReflection(p, q) << endl;

    return 0;
}
