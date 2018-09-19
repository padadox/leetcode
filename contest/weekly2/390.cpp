
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
    int lastRemaining(int n) {
        if(n == 1) {
            return 1;
        }

        if(n <= 5) {
            return 2;
        }

        int m = n >> 1;
        int r = 1 - (m & 1);
        int a = lastRemaining(m >> 1);

        return ((a*2) - r) * 2;
    }
};

int main(int argc, const char *argv[])
{
    int n = 0;
    cin >> n;
    Solution s;
    cout << s.lastRemaining(n) << endl;
    return 0;
}
