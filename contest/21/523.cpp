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
    bool checkSubarraySum(vector<int>& nums, int k) {
        int previous = 1;
        for(auto x: nums) {
            if(x == 0) {
                if(previous == 0) {
                    return true;
                }
            }

            previous = x;
        }

        if(k == 0) {
            return false;
        }

        set<int> remains;
        remains.insert(0);
        int sum = 0;
        int pre = 0;
        int pad = k;
        for(auto x: nums) {
            sum += x;
            int remain = sum % k;
            if(remain == pre) {
                remain = pad++;
            }
            remains.insert(remain);
            pre = remain;
        }

        if(remains.size() <= nums.size()) {
            return true;
        }
        return false;
    }
};
