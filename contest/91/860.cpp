
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
    bool lemonadeChange(vector<int>& bills) {
        int cnt_5 = 0;
        int cnt_10 = 0;

        for (auto x: bills) {
            if(5 == x) {
                cnt_5++;
                continue;
            }

            if(10 == x) {
                cnt_5--;
                cnt_10++;
            }
            else if(20 == x) {
                if(cnt_10 > 0) {
                    cnt_10--;
                    cnt_5--;
                }
                else {
                    cnt_5 -= 3;
                }
            }

            if(cnt_5 < 0) {
                return false;
            }
        }

        return true;
    }
};
