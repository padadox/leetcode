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
    int numPermsDISequence(string S) {
        vector<ll> mcnt1(S.size()+1, 0);
        vector<ll> mcnt2(S.size()+1, 0);

        vector<ll> *pcnt1 = &mcnt1;
        vector<ll> *pcnt2 = &mcnt2;

        mcnt1[0] = 1;
        for(int i = 1;i <= S.size(); ++i) {

            vector<ll>& cnt1 = *pcnt1;
            vector<ll>& cnt2 = *pcnt2;

            if(S[i-1] == 'D') {
                ll sum = 0;
                for(int j = i-1; j >= 0; j--) {
                    sum += cnt1[j];
                    sum %= MOD;
                    cnt2[j] = sum;
                }
            }
            else {
                cnt2[0] = 0;
                ll sum = 0;
                for(int j = 0; j < i; j++) {
                    sum += cnt1[j];
                    sum %= MOD;
                    cnt2[j+1] = sum;
                }
            }

            swap(pcnt1, pcnt2);
        }

        ll ans = 0;
        for(auto x: *pcnt1) {
            ans += x;
            ans %= MOD;
        }

        return ans;
    }
};


int main(int argc, const char *argv[])
{
    string A = "II";
    cout << Solution().numPermsDISequence(A);
    return 0;
}
