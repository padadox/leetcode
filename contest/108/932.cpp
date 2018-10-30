// 20181029 21:18
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


/**
 * 问题描述
 *932. Beautiful Array
Virtual User Accepted: 32
Virtual User Tried: 109
Virtual Total Accepted: 32
Virtual Total Submissions: 109
Difficulty: Medium
For some fixed N, an array A is beautiful if it is a permutation of the integers 1, 2, ..., N, such that:

For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].

Given N, return any beautiful array A.  (It is guaranteed that one exists.)

 

Example 1:

Input: 4
Output: [2,1,4,3]
Example 2:

Input: 5
Output: [3,1,2,5,4]
 

Note:

1 <= N <= 1000
 */


/**
 * 解决方案
 * 方法1( O(NLogN) ): 
 * 1)生成1..N数组；
 * 2)将数组数组分成两部分，将数组的偶数索引部分放到前半部分，奇数索引部分放到后半部分；然后对两部分继续递归处理，直到需要处理的数组长度<=2，结束。
 *
 * 方法2( O(N) )：
 * 直接递归生成数组。
 * 先生成长为1的数组，然后对数组元素迭代，生成长为2的数组，依次生产4, 8, 16...数组，直到长度满足要求。
 *
 *
 *
 */


class Solution1 {
public:
    vector<int> beautifulArray(int N) {
        vector<int> nums(N, 0);
        for(int i = 0; i < N; i++) {
            nums[i] = i + 1;
        }

        vector<int> nums2 = nums;
        process(nums, nums2, 0, N);

        int i = 0;
        int n = 2;
        while(n < N) {
            n <<= 1;
            i++;
        }

        if(i & 1) {
            return nums2;
        }

        return nums;
    }

    void process(vector<int> &nums, vector<int>& nums2, int start, int end) {
        int i = 0;
        int j = start;

        if(end - start <= 2) {
            for(i = start; i < end; i++) {
                nums2[i] = nums[i];
            }

            return;
        }

        for(i = start; i < end; i += 2) {
            nums2[j++] = nums[i];
        }

        for(i = start+1; i < end; i += 2) {
            nums2[j++] = nums[i];
        }

        cout << start << "to" << end << endl;
        for(int i = start; i < end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        for(int i = start; i < end; i++) {
            cout << nums2[i] << " ";
        }
        cout << endl;

        process(nums2, nums, start, start + (end - start + 1) / 2);
        process(nums2, nums, start + (end - start + 1) / 2, end);
        for(int i = start; i < end; i++) {
            cout << nums2[i] << " ";
        }
        cout << endl;

    }
};

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {

    public:
        vector<int> beautifulArray(int N) {
            vector<int> ans(N, 0);
            int size = 1;
            ans[0] = 1;
            while(size < N) {
                int j = 0;
                for(int i = 0; i < size; i++) {
                    int v = ans[i] * 2 - 1;
                    if(v <= N) {
                        ans[j++] = v;
                    }
                }

                size = j;
                for(int i = 0; i < size; i++) {
                    int v = ans[i] + 1;
                    if(v <= N) {
                        ans[j++] = v;
                    }
                }

                size = j;
            }

            return ans;
        }
};
