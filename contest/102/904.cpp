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
    int totalFruit(vector<int>& tree) {
        int type[2] = {-1, -1};
        int type_begin[2] = {0, 0};

        int begin = 0;
        int max = 0;

        for(int i = 0; i < tree.size(); ++i) {
            if(tree[i] == type[1]) {
                continue;
            }

            int pre_pre = type[0];

            type[0] = type[1];
            type_begin[0] = type_begin[1];

            type[1] = tree[i];
            type_begin[1] = i;

            if(pre_pre == tree[i]) {
                continue;
            }

            int len = i - begin;
            if(len > max) {
                max = len;
            }
            begin = type_begin[0];
        }

        int len = tree.size() - begin;
        if(len > max) {
            max = len;
        }
        return max;
    }
};

int main(int argc, const char *argv[])
{
    vector<int> A{0};
    cout << Solution().totalFruit(A);
    
    return 0;
}
