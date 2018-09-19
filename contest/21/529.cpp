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
    int m = 0;
    int n = 0;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board.size();

        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        trace(board, click[0], click[1], 0, 0);
        return board;
    }

    void trace(vector<vector<char>> &board, int i, int j, int r, int b) {
    }

    int count(vector<vector<char>>& board, int i, int j) {
        int cnt = 0;
        cnt += count_one(board, i-1, j-1);
        cnt += count_one(board, i-1, j);
        cnt += count_one(board, i-1, j+1);
        cnt += count_one(board, i,   j-1);
        cnt += count_one(board, i,   j+1);
        cnt += count_one(board, i+1, j-1);
        cnt += count_one(board, i+1, j);
        cnt += count_one(board, i+1, j+1);

        return cnt;
    }

    int count_one(vector<vector<char>> &board, int i, int j) {
        if(board[i][j] == 'M') {
            return 1;
        }

        return 0;
    }
};

/*
class Solution {

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        trace(board, click[0], click[1]);

        return board;
    }

    void trace(vector<vector<char>> &board, int i, int j) {
        if(i < 0 || i >= board.size()) {
            return;
        }

        if(j < 0 || j >= board[0].size()) {
            return;
        }

        if(board[i][j] != 'M' && board[i][j] != 'E') {
            return;
        }

        int cnt = count(board, i, j);
        if(cnt != 0) {
            board[i][j] = '0' + cnt;
            return;
        }

        board[i][j] = 'B';

        trace(board, i-1, j-1);
        trace(board, i-1, j);
        trace(board, i-1, j+1);
        trace(board, i,   j-1);
        trace(board, i,   j+1);
        trace(board, i+1, j-1);
        trace(board, i+1, j);
        trace(board, i+1, j+1);
    }

    int count(vector<vector<char>>& board, int i, int j) {
        int cnt = 0;
        cnt += count_one(board, i-1, j-1);
        cnt += count_one(board, i-1, j);
        cnt += count_one(board, i-1, j+1);
        cnt += count_one(board, i,   j-1);
        cnt += count_one(board, i,   j+1);
        cnt += count_one(board, i+1, j-1);
        cnt += count_one(board, i+1, j);
        cnt += count_one(board, i+1, j+1);

        return cnt;
    }

    int count_one(vector<vector<char>> &board, int i, int j) {
        if(i < 0 || i >= board.size()) {
            return 0;
        }

        if(j < 0 || j >= board[0].size()) {
            return 0;
        }

        if(board[i][j] == 'M') {
            return 1;
        }

        return 0;
    }

};
*/
