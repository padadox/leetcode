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
    int kSimilarity(string A, string B) {
        map<char, vector<char>> replace;

        for(size_t i = 0; i < A.size(); ++i) {
            if(A[i] == B[i]) {
                continue;
            }

            replace[A[i]].push_back(B[i]);
        }

        int ans = 0;
        for(auto &x: replace) {
            char c = x.first;
            vector<char> &v = x.second;

            for(auto s: v) {
                char cur = s;
                int loop_len = 1;
                cout << c << " ";
                while(cur != c) {
                    cout << cur << " ";
                    char tmp = replace[cur].back();
                    replace[cur].pop_back();
                    cur = tmp;
                    loop_len++;
                }

                ans += loop_len - 1;
                cout << endl;
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    string A = "abc";
    string B = "bca";

    cin >> A;
    cin >> B;
    Solution s;
    cout << s.kSimilarity(A, B);

    return 0;
}
