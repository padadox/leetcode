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
    bool validTicTacToe(vector<string>& board) {
        int x_cnt = 0;
        int o_cnt = 0;
        vector<vector<set<char>>> s(3, vector<set<char>>(3, set<char>()));



        for(size_t i = 0; i < board.size(); ++i) {
            for(size_t j = 0; j < board.size(); ++j) {
                if(board[i][j] == 'X') {
                    x_cnt++;
                }
                else if(board[i][j] == 'O') {
                    o_cnt++;
                }

                s[0][i].insert(board[i][j]);
                s[1][j].insert(board[i][j]);

                if(i == j) {
                    s[2][0].insert(board[i][j]);
                }

                if(i + j == 2) {
                    s[2][1].insert(board[i][j]);
                }
            }
        }

        if(x_cnt < o_cnt) {
            return false;
        }

        if(o_cnt + 1 < x_cnt) {
            return false;
        }

        set<char> win_char;
        for(auto &x: s) {
            for(auto &y: x) {
                if(y.size() == 1) {
                    if(*y.cbegin() != ' ') {
                        win_char.insert(*y.cbegin());
                    }
                }
            }
        }

        if(win_char.empty()) {
            return true;
        }

        if(win_char.size() > 1) {
            return false;
        }

        if(*win_char.begin() == 'X') {
            if(x_cnt != o_cnt + 1) {
                return false;
            }
        }
        else {
            if(x_cnt != o_cnt) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, const char *argv[])
{
    vector<string> board{"XOX", "O O", "XOX"};
    cout << Solution().validTicTacToe(board);
    return 0;
}
