// 20181014 23:40
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

using int64 = long long;
using pii = pair<int,int>;
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const int64 MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/**
 *923. 3Sum With Multiplicity
Given an integer array A, and an integer target, return the number of tuples i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.

As the answer can be very large, return it modulo 10^9 + 7.

 

Example 1:

Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (A[i], A[j], A[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: A = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
 

Note:

3 <= A.length <= 3000
0 <= A[i] <= 100
0 <= target <= 300
 *
 */

/*
 * 方法:
 * 1、排序
 * 2、合并相同数字
 * 3、二分查找
 *
 * 优化：
 * 1、二分查找结束位置的优化
 *
 * 错误：
 * 1、遗忘了相同数字可以同时选择的情况
 */

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        if(A.empty()) {
            return 0;
        }

        sort(A.begin(), A.end());
        vector<int> values;
        vector<int> cnt;

        int c = 1;
        for(int i = 1; i < A.size(); i++) {
            if(A[i] == A[i-1]) {
                c++;
                continue;
            }

            values.push_back(A[i-1]);
            cnt.push_back(c);
            c = 1;
        }

        values.push_back(A[A.size()-1]);
        cnt.push_back(c);

        int64 ans = 0;
        for(auto first = values.begin(); first != values.end(); first++) {
            auto end = values.end();
            for(auto second = first; end - second >= 0; second++) {
                int to_search = target - *first - *second;
                auto pos = lower_bound(second, end, to_search);
                if(pos == end) {
                    continue;
                }

                if(*pos > to_search) {
                    end = pos;
                    continue;
                }

                end = pos;

                int i = first - values.begin();
                int j = second - values.begin();
                int k = pos - values.begin();

                if(i == j) {
                    if(j == k) {
                        ans += (int64)1 * cnt[i] * (cnt[i]-1) * (cnt[i]-2) / 6;
                        ans %= MOD;
                    }
                    else {
                        ans += (int64)1 *cnt[i] * (cnt[i]-1) * cnt[k] / 2;
                        ans %= MOD;
                    }
                }
                else if(j == k) {
                    ans += (int64)1 *cnt[i] * cnt[j] * (cnt[j]-1) / 2;
                    ans %= MOD;
                }
                else {
                    ans += (int64)1 *cnt[i] * cnt[j] * cnt[k];
                    ans %= MOD;
                }
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<int> A{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    cout << Solution().threeSumMulti(A, 8) << endl;
    
    return 0;
}
