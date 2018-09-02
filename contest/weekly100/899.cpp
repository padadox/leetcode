
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
    string orderlyQueue(string S, int K) {
        if(K > 1) {
            sort(S.begin(),  S.end());
            return S;
        }

        
        string m = S;

        for(size_t i = 1; i < S.size(); ++i) {
            string x = S.substr(i) + S.substr(0, i);
            if(x < m) {
                m = x;
            }
        }

        return m;
    }
};
