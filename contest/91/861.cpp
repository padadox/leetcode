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
    int matrixScore(vector<vector<int>>& A) {
        int r = A.size();
        int c = A[0].size();
        int shift_width = c-1;
        int ans = r << shift_width;

        for(int j = 1; j < c; ++j) {
            shift_width--;
            int cnt = 0;
            for(int i = 0; i < r; ++i) {
                cnt += A[i][j] ^ A[i][0];
            }

            ans += max(cnt, r-cnt) << shift_width;
        }

        return ans;
    }
};
