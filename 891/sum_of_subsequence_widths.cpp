/*
 *
 
Given an array of integers A, consider all non-empty subsequences of A.

For any sequence S, let the width of S be the difference between the maximum and minimum element of S.

Return the sum of the widths of all subsequences of A. 

As the answer may be very large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [2,1,3]
Output: 6
Explanation:
Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.*
 */

#include <vector>
#include <algorithm>
using namespace std;

struct Cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end(), Cmp());

        long long sum = 0;
        long long mod = 1000000000 + 7;

        vector<long long> factor;
        factor.resize(A.size());
        factor[0] = 0;
        for(size_t i = 1; i < factor.size(); ++i) {
            factor[i] = ((factor[i-1] * 2 ) + 1) % mod;
        }


        long long cnt = 0;
        size_t n = A.size();
        for(size_t i = 0; i + 1 < n; ++i) {
            long long diff = A[i] - A[i+1];
            cnt += factor[n-i-1] - factor[i];
            cnt %= mod;
            sum += diff * cnt;
            sum %= mod;
        }

        return (sum + mod) % mod;
    }
};

#include <iostream>

int main(int argc, const char *argv[])
{
    Solution s;

    vector<int> A{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};
    int sum = s.sumSubseqWidths(A);

    cout << sum << endl;

    return 0;
}
