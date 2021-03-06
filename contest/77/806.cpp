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
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line = 0;
        int sum = 0;

        for(auto x: S) {
            sum += widths[x-'a'];
            if(sum > 100) {
                line++;
                sum = widths[x-'a'];
            }
        }

        line++;

        vector<int> ans(2);
        ans[0] = line;
        ans[1] = sum;

        return ans;
    }
};
