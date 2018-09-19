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

struct Cmp {
    bool operator()(string &a, string& b) {
        if(a.size() == b.size()) {
            return a > b;
        }

        return a.size() < b.size();
    }
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        priority_queue<string, vector<string>, Cmp> ans;

        for(auto &x: d) {
            if(x.size() > s.size()) {
                continue;
            }

            size_t i = 0;
            size_t j = -1;

            for(i = 0; i < x.size(); ++i) {
                j++;
                for(; j < s.size() && s[j] != x[i]; j++); 
                if(j >= s.size()) {
                    break;
                }
            }

            if(i < x.size()) {
                continue;
            }

            ans.push(x);
        }

        if(!ans.empty()) {
            return ans.top();
        }

        return "";
    }
};
