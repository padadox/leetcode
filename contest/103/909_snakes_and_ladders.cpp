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
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> flag(n * n + 1, false);
        q.push(make_pair(1, 0));
        flag[1] = true;
        queue<string> path;
        path.push("1, ");

        int target = n * n;
        int ans = 0;
        while(!q.empty()) {
            auto c = q.front();
            auto p = path.front();
            path.pop();
            q.pop();
            int pos = c.first;
            int level = c.second;
            if(pos == target) {
                ans = level;
                cout << "Path " << p << endl;
                break;
            }

            for(int i = 1; i <= 6 && pos + i <= target; i++) {
                int cur = pos + i;
                int cur_level = level + 1;
                string cur_path = p;

                int row = (cur - 1) / n;
                int col = (cur - 1) % n;

                if(row & 1) {
                    col = n - 1 - col;
                }

                row = n - 1 - row;

                int ladder = board[row][col];
                if(-1 != ladder) {
                    char tmp[10];
                    sprintf(tmp, "%d->", cur);
                    cur_path += tmp;
                    cur = ladder;
                }

                if(flag[cur]) {
                    continue;
                }

                char tmp[10];
                sprintf(tmp, "%d, ", cur);
                cur_path += tmp;

                q.push(make_pair(cur, cur_level));
                path.push(cur_path);
                flag[cur] = true;
            }
        }
        
        if(0 == ans) {
            ans = -1;
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    // vector<vector<int>> board {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    vector<vector<int>> board 
    /*
    {
        {-1, -1, -1, 46, 47, -1, -1, -1},
        {51, -1, -1, 63, -1, 31, 21, -1},
        {-1, -1, 26, -1, -1, 38, -1, -1},
        {-1, -1, 11, -1, 14, 23, 56, 57},
        {11, -1, -1, -1, 49, 36, -1, 48},
        {-1, -1, -1, 33, 56, -1, 57, 21},
        {-1, -1, -1, -1, -1, -1,  2, -1},
        {-1, -1, -1,  8,  3, -1,  6, 56}
    };
    */
    // {{-1, -1}, {-1, 3}};
{{-1,5,-1,-1,17,6,-1},{41,28,-1,-1,-1,27,-1},{35,42,-1,-1,-1,-1,4},{7,32,-1,25,-1,43,-1},{-1,26,5,-1,-1,-1,25},{28,-1,-1,5,-1,-1,41},{-1,42,28,25,-1,7,28}};

    cout << Solution().snakesAndLadders(board) << endl;
    
    return 0;
}
