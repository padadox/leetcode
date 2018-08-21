#define MOD 1000000007

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        vector<long long> pp = {1};
        while (pp.size() <= A.size())
            pp.push_back(pp.back() * 2 % MOD);
        sort(A.begin(), A.end());
        long long ans = 0;
        for (int i = 0; i < A.size(); i++) {
            ans = (ans + A[i] * pp[i]) % MOD;
            ans = (ans + MOD - A[i] * pp[A.size() - 1 - i] % MOD) % MOD;
        }
        return (int)ans;
    }
};
