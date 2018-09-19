
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
#include <climits>
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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int left = INT_MAX;
        int bottom = INT_MAX;
        int top = INT_MIN;
        int right = INT_MIN;

        ll sum_area = 0;
        for(auto & x: rectangles) {
            if(x[0] < left) {
                left = x[0];
            }

            if(x[1] < bottom) {
                bottom = x[1];
            }

            if(x[2] > right) {
                right = x[2];
            }

            if(x[3] > top) {
                top = x[3];
            }

            sum_area += (x[2] - x[0]) * (x[3] - x[1]);
        }

        if((top-bottom)*(right-left) != sum_area) {
            return false;
        }

        map<pair<int, int>, int> top_left;
        map<pair<int, int>, int> top_right;
        map<pair<int, int>, int> bottom_right;
        for(auto &x: rectangles) {

        }

        return true;
    }
};
