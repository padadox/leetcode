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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.empty()) {
            return 0;
        }

        vector<int> index(position.size());
        iota(index.begin(), index.end(), 0);

        sort(index.begin(), index.end(), [&position, &speed](int i, int j) -> bool
                {
                return position[i] > position[j];
                });

        for(auto x: index) {
            cout << " " << x;
        }
        cout << endl;

        int cnt = 1;
        int start = index[0];

        for(size_t i = 1; i < index.size(); ++i) {
            cout << start << endl;
            int idx = index[i];

            if((ll)(position[start] - position[idx]) * speed[start] <= (ll)(speed[idx] - speed[start]) * (target - position[start])) {
                continue;
            }

            start = idx;
            cnt++;
        }

        return cnt;
    }
};

int main(int argc, const char *argv[])
{
    vector<int> A{620831,145366,229113,144305,382893,514856,171642,87230,409014,65613};
    vector<int> B{327716,69772,667805,856849,78755,606982,696937,207697,275337,290550};
    int target = 660732;


    cout << Solution().carFleet(target, A, B);
    
    return 0;
}
