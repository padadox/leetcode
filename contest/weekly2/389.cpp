
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
    char findTheDifference(string s, string t) {
        int cnt[26] = {0};
        int cnt2[26] = {0};

        for(auto x: s) {
            cnt[x-'a']++;
        }

        for(auto x: t) {
            cnt2[x-'a']++;
        }

        char i = 0;
        for(i = 0; i < 26; ++i) {
            if (cnt[i] != cnt2[i]) {
                break;
            }
        }

        return 'a' + i;
    }
};
