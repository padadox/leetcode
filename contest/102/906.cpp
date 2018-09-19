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
    int superpalindromesInRange(string L, string R) {
        ll l = atoll(L.c_str());
        ll r = atoll(R.c_str());

        int bits_l = count_bits(l);
        int bits_r = count_bits(r);
    }

    int count_bits(ll n) {
        int x = 0;
        while(n) {
            x++;
            n /= 10;
        }

        return x;
    }
};
