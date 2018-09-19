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
    int scoreOfParentheses(string S) {
        stack<char> s;
        bool pre_left = false;
        int ans = 0;

        for(auto x: S) {
            if(x == '(') {
                pre_left = true;
                s.push(x);
                continue;
            }

            if(x == ')') {
                s.pop();
                if(pre_left) {
                    ans += 1 << s.size();
                }

                pre_left = false;
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    string x;
    cin >> x;
    cout << Solution().scoreOfParentheses(x);
    
    return 0;
}
