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


class StockSpanner {
public:
    vector<int> prices;
    vector<int> span;

    const int MAX_CNT = 10000;

    StockSpanner() {
        prices.reserve(MAX_CNT);
        span.reserve(MAX_CNT);
    }
    
    int next(int price) {
        prices.push_back(price);

        int cnt = 1;
        int i = prices.size() - 2;
        while(i >= 0 && prices[i] <= price) {
            cnt += span[i];
            i -= span[i];
        }

        span.push_back(cnt);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
