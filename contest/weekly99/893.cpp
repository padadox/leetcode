
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
    string hash(string & s) {
        string a = "";
        string b = "";
        for(int i = 0; i < s.size(); i += 2) {
            a += s[i];
        }
        for(int i = 1; i < s.size(); i += 2) {
            b += s[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a + b;
    }
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> s;
        for(auto a: A) {
            s.insert(hash(a));
        }

        return s.size();
    }
};
