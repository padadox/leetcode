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
 *In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.  

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.

 

Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation: 
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.
 

Note:

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
 */
class TopVotedCandidate {
    vector<int> winner;
    vector<int> times;
public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        winner.reserve(times.size());
        this->times = times;
        unordered_map<int, int>cnt;

        for(size_t i = 0; i < times.size(); ++i) {
            int p = persons[i];
            if(cnt.end() == cnt.find(p)) {
                cnt[p] = 1;
            }
            else {
                cnt[p]++;
            }

            if((0 == i) || (cnt[p] >= cnt[winner[i-1]])) {
                winner.push_back(p);
            }
            else {
                winner.push_back(winner[i-1]);
            }
        }
    }
    
    int q(int t) {
        auto x = upper_bound(times.begin(), times.end(), t);
        if(times.end() == x) {
            return winner.back();
        }
        return winner[x - times.begin() - 1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */


int main(int argc, const char *argv[])
{
    vector<int> persons {0,1,1,0,0,1,0};
    vector<int> times {0,5,10,15,20,25,30};
    TopVotedCandidate t(persons, times);
    vector<int> query {3, 12, 25, 15, 24, 8};
    for(auto x: query) {
        cout << x << ":" << t.q(x) << endl;
    }
    return 0;
}
