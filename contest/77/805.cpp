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
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        sort(A.rbegin(), A.rend()); // Optimization
        for (int i = 1; i <= m; ++i) 
            if (totalSum*i%n == 0 && combinationSum(A, 0, i, totalSum*i/n)) return true;
        return false;
    }
    bool combinationSum(vector<int>& nums, int idx, int k, int tar) {
        if (tar > k * nums[idx]) return false; // Optimization, A is sorted from large to small
        if (k == 0) return tar == 0;
        for (int i = idx; i <= nums.size()-k; ++i) 
            if (nums[i] <= tar && combinationSum(nums, i+1, k-1, tar-nums[i])) return true;
        return false;
    }
};
