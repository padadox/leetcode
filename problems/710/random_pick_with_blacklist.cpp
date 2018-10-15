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
#include <random>
#include <functional>
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


/*
 *Given a blacklist B containing unique integers from [0, N), write a function to return a uniform random integer from [0, N) which is NOT in B.

Optimize it such that it minimizes the call to system’s Math.random().

Note:

1 <= N <= 1000000000
0 <= B.length < min(100000, N)
[0, N) does NOT include N. See interval notation.
Example 1:

Input: 
["Solution","pick","pick","pick"]
[[1,[]],[],[],[]]
Output: [null,0,0,0]
Example 2:

Input: 
["Solution","pick","pick","pick"]
[[2,[]],[],[],[]]
Output: [null,1,1,1]
Example 3:

Input: 
["Solution","pick","pick","pick"]
[[3,[1]],[],[],[]]
Output: [null,0,0,2]
Example 4:

Input: 
["Solution","pick","pick","pick"]
[[4,[2]],[],[],[]]
Output: [null,1,3,1]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has two arguments, N and the blacklist B. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.
 *
 */

class Solution {
    int N;
    vector<int> blacklist_pos;
    int M;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> dis;
public:
    Solution(int N, vector<int> blacklist) {
        this->N = N;
        sort(blacklist.begin(), blacklist.end());
        M = N - blacklist.size();
        blacklist_pos.resize(blacklist.size() + 1);
        for(size_t i = 0; i < blacklist.size(); ++i) {
            blacklist_pos[i] = blacklist[i] - i;
        }
        blacklist_pos[blacklist.size()] = M;
        dis = std::uniform_int_distribution<int>(1, M);
    }
    
    int pick() {
        int idx = dis(generator);
        auto it = lower_bound(blacklist_pos.begin(), blacklist_pos.end(), idx);
        int pos = it - blacklist_pos.begin();
        int ans = pos + idx - 1;

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

int main(int argc, const char *argv[])
{
    Solution s(2, vector<int>());
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    cout << s.pick() << endl;
    
    return 0;
}
