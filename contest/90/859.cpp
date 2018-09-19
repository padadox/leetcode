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
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) {
            return false;
        }

        vector<char> diff;
        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] != B[i]) {
                diff.push_back(A[i]);
                diff.push_back(B[i]);
                if(diff.size() > 4) {
                    return false;
                }
            }
        }

        if(diff.size() == 2) {
            return false;
        }

        if(diff.size() == 0) {
            set<char> s;
            s.insert(A.begin(), A.end());
            if(s.size() == A.size()) {
                return false;
            }
            else {
                return true;
            }
        }

        if(diff[0] != diff[3] || diff[1] != diff[2]) {
            return false;
        }

        return true;
    }
};
