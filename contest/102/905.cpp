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
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even;
        vector<int> odd;

        even.reserve(A.size());
        odd.reserve(A.size());

        for(auto x: A) {
            if(x & 1) {
                odd.push_back(x);
            }
            else {
                even.push_back(x);
            }
        }

        even.insert(even.end(), odd.begin(), odd.end());

        return even;
    }
};
