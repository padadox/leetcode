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
 *
 * 曾尝试将状态定义为(mouse位置，cat位置，下一个要行动的位置）, 但存在将1, 2误判为0的问题：
 * 原因：
 * 1、对于最终结果不为0 的情况，在老鼠钻洞，或猫抓到老鼠之前，部分路径会出现反复，因此会存在暂时将相应状态的结果判为0的情况；
 * 2、对于(mouse位置，cat位置，下一个要行动的位置）的情况，相当于(mouse位置，cat位置)状态划分为子状态。一个状态的结果，必须对于所有子状态全部成立。子状态的结果可能来源于其他子状态的判断过程（由于路径的反复，会存在误判为0的情况），会导致最终结果错误。
 * 3、对于状态(mouse位置， cat位置), 由于其每个状态的判断都是完整的(最终结果来源于实际判断，而不是缓存），会将结果纠正； * //// 该原因分析还不完全确定。
 *
 * 本质上可能在于已访问标记的处理（不应该返回0, 而在重复点不继续探索即可)。
 */

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        map<pii, char> result;
        set<pii> s;
        return catMouse(graph, result, s, make_pair(1, 2));
    }

    int catMouse(vector<vector<int>>& graph, map<pii, char> &result, set<pii> &s, pii pos) {
        int mouse = pos.first;
        int cat = pos.second;

        cout << s.size() << " " << mouse << " " << cat << endl;

        auto it = result.find(pos);
        if(it != result.end()) {
            return it->second;
        }

        if(s.find(pos) != s.end()) {
            result[pos] = 0;
            return 0;
        }
        s.insert(pos);

        bool flag1_outer = false;
        bool flag2_outer = true;
        for(auto x: graph[mouse]) {
            if(0 == x) {
                flag1_outer = true;
                flag2_outer = false;
                break;
            }
            
            if(x == cat) {
                continue;
            }

            bool flag1_inner = true;
            bool flag2_inner = false;
            for(auto y: graph[cat]) {
                if(0 == y) {
                    continue;
                }
                if(y == x) {
                    flag2_inner = true;
                    flag1_inner = false;
                    break;
                }

                int ret = catMouse(graph, result, s, make_pair(x, y));
                if(2 == ret) {
                    flag2_inner = true;
                    flag1_inner = false;
                    break;
                }
                if(1 != ret) {
                    flag1_inner = false;
                }
            }

            if(flag1_inner) {
                flag1_outer = true;
                flag2_outer = false;
                break;
            }
            if(!flag2_inner) {
                flag2_outer = false;
            }
        }

        s.erase(pos);

        int ans = 0;
        if(flag1_outer) {
            ans = 1;
        } 
        else if(flag2_outer) {
            ans = 2;
        }

        result[pos] = ans;

        return ans;
    }
};


int main(int argc, const char *argv[])
{
    vector<vector<int>> graph 
    // {{4,6,7,8,9},{3,4,5,6,7,8,9},{3,8,9},{1,2,6},{1,5,6,9,0},{1,4},{1,3,4,7,8,0},{1,6,0},{1,2,6,9,0},{1,2,4,8,0}};
    // {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
    //{{1}, {4, 0}, {3}, {2}, {1}};
    {{}, {5}, {3}, {2, 4}, {3, 5}, {1, 4}};
    // {{3,4,6,7,9,15,16,18},{4,5,8,19},{4,5,6,7,9,18},{0,10,11,15},{0,1,2,6,10,12,14,16},{1,2,7,9,15,17,18},{0,2,4,7,9,10,11,12,13,14,15,17,19},{0,2,5,6,9,16,17},{1,9,14,15,16,19},{0,2,5,6,7,8,10,11,13,15,16,17,18},{3,4,6,9,17,18},{3,6,9,12,19},{4,6,11,15,17,19},{6,9,15,17,18,19},{4,6,8,15,19},{0,3,5,6,8,9,12,13,14,16,19},{0,4,7,8,9,15,17,18,19},{5,6,7,9,10,12,13,16},{0,2,5,9,10,13,16},{1,6,8,11,12,13,14,15,16}};
    cout << Solution().catMouseGame(graph) << endl;

    return 0;
}
