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


/*
 *
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
 *
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>> edges(N+1);
        for(auto &x: times) {
            edges[x[0]].emplace_back(x[1], x[2]);
        }

        min_queue<pii> q;

        q.push(make_pair(0, K));
        vector<bool> flag(N, false);
        int cnt = 0;
        int max = 0;
        while(!q.empty()) {
            auto x = q.top();
            q.pop();

            auto dis = x.first;
            auto idx = x.second;

            if(flag[idx]) {
                continue;
            }

            flag[idx] = true;
            max = dis;
            cnt++;

            for(auto &y: edges[idx]) {
                int target, time;
                tie(target, time) = y;

                if(flag[idx]) {
                    continue;
                }

                auto cur_dis = dis + time;
                q.emplace(cur_dis, target);
            }
        }

        if(cnt < N) {
            return -1;
        }

        return max;
    }
};
