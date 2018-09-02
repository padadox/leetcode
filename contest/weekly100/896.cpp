
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
    bool isMonotonic(vector<int>& A) {
        if(A.empty()) {
            return true;
        }

        /*
        if(A.size() <= 1) {
            return true;
        }
        */

        int flag = A.back() - A.front();
        
        if(flag >= 0) {
            for(size_t i = 0; i + 1 < A.size(); i++) {
                if(A[i] > A[i+1]) {
                    return false;
                }
            }

            return true;
        }
        else {
            for(size_t i = 0; i + 1 < A.size(); i++) {
                if(A[i] < A[i+1]) {
                    return false;
                }
            }

            return true;
        }
    }
};
