// 20180930 22:44
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
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/**
 *
 *A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:

If ever the Cat occupies the same node as the Mouse, the Cat wins.
If ever the Mouse reaches the Hole, the Mouse wins.
If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 

Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0
 

Note:

3 <= graph.length <= 50
It is guaranteed that graph[1] is non-empty.
It is guaranteed that graph[2] contains a non-zero element. 
 *
 */

/**
 * 方法：
 * 使用递归。
 * 对于当前状态(mouse位置， cat位置)结果的判断：
 * 1、如果递归路径中出现该状态，则平局；
 * 2、如果存在mouse的一个选择，对于所有cat的选择，子过程mouse都胜利，则mouse胜出；
 * 3、如果对于mouse的所有选择，cat均存在一个选择，子过程cat胜出，则Cat胜出；
 * 4、否则，平局。
 */

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        map<tiii, char> result;
        set<tiii> s;
        return catMouse(graph, result, s,{1, 2, 1});
    }

    int catMouse(vector<vector<int>>& graph, map<tiii, char> &result, set<tiii> &s, tiii state) {
        int mouse, cat, cur;
        tie(mouse, cat, cur) = state;

        // cout << s.size() << "\t " << mouse << " " << cat << " " << cur << endl;

        auto it = result.find(state);
        result.end();
        if(it != result.end()) {
            return it->second;
        }

        /*
        if(s.find(state) != s.end()) {
            result[state] = 0;
            return 0;
        }
        */
        if(mouse == 1 && cat == 2 && cur == 1) {
            if(s.size() > 1) {
                return 0;
            }
        }

        s.insert(state);

        bool flag1_any = false;
        bool flag1_all = true;
        bool flag2_any = false;
        bool flag2_all = true;
        for(auto x: graph[cur]) {
            int sub_ans = 0;
            int sub_cat = cat;
            int sub_mouse = mouse;
            if(cur == mouse) {
                sub_mouse = x;
                if(0 == x) {
                    sub_ans = 1;
                }
                else if(x == cat) {
                    sub_ans = 2;
                }
            }
            else {
                sub_cat = x;
                if(0 == x) {
                    continue;
                }
                else if(x == mouse) {
                    sub_ans = 2;
                }
            }

            auto sub = tiii{sub_mouse, sub_cat, sub_mouse + sub_cat - x};
            if(s.end() != s.find(sub)) {
                if(sub == tiii{1, 2, 1}) {
                    sub_ans = 0;
                }
                else {
                    continue;
                }
            }
            else {
                if(0 == sub_ans) {
                    sub_ans = catMouse(graph, result, s, sub);
                }
            }

            if(1 == sub_ans) {
                flag1_any = true;
                flag2_all = false;
            }
            else if(2 == sub_ans) {
                flag2_any = true;
                flag1_all = false;
            }
            else {
                flag1_all = false;
                flag2_all = false;
            }
        }
        s.erase(state);

        int ans = 0;
        if(mouse == cur) {
            if(flag1_any) {
                ans = 1;
            }
            else if(flag2_all){
                ans = 2;
            }
        }
        else {
            if(flag2_any) {
                ans = 2;
            }
            else if(flag1_all){
                ans = 1;
            }
        }

        result[state] = ans;
        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<vector<int>> graph 
    //{{4,6,7,8,9},{3,4,5,6,7,8,9},{3,8,9},{1,2,6},{1,5,6,9,0},{1,4},{1,3,4,7,8,0},{1,6,0},{1,2,6,9,0},{1,2,4,8,0}};
     {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
    //{{1}, {4, 0}, {3}, {2}, {1}};
    //{{}, {5}, {3}, {2, 4}, {3, 5}, {1, 4}};
    // {{3,4,6,7,9,15,16,18},{4,5,8,19},{4,5,6,7,9,18},{0,10,11,15},{0,1,2,6,10,12,14,16},{1,2,7,9,15,17,18},{0,2,4,7,9,10,11,12,13,14,15,17,19},{0,2,5,6,9,16,17},{1,9,14,15,16,19},{0,2,5,6,7,8,10,11,13,15,16,17,18},{3,4,6,9,17,18},{3,6,9,12,19},{4,6,11,15,17,19},{6,9,15,17,18,19},{4,6,8,15,19},{0,3,5,6,8,9,12,13,14,16,19},{0,4,7,8,9,15,17,18,19},{5,6,7,9,10,12,13,16},{0,2,5,9,10,13,16},{1,6,8,11,12,13,14,15,16}};
    cout << Solution().catMouseGame(graph) << endl;

    return 0;
}
