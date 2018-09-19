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
 *Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Example 1:
Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.
Example 2:
Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.
 

Note:

graph will have length in range [1, 100].
graph[i] will contain integers in range [0, graph.length - 1].
graph[i] will not contain i or duplicate values.
The graph is undirected: if any element j is in graph[i], then i will be in graph[j].
 */

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<char> color;
        color.resize(graph.size(), -1);
        
        queue<int> q;
        for(int i = 0; i < graph.size(); ++i) {
            if(color[i] != -1) {
                continue;
            }

            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int cur = q.front();
                q.pop();

                int cur_color = color[cur];
                for(int j = 0; j < graph[cur].size(); j++) {
                    auto k = graph[cur][j];
                    if(color[k] == cur_color) {
                        return false;
                    }

                    if(color[k] == -1){
                        color[k] = 1 - cur_color;
                        q.push(k);
                    }
                }
            }
        }

        return true;
    }
};


int main(int argc, const char *argv[])
{
    vector<vector<int>> A{{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    cout << Solution().isBipartite(A);
    
    return 0;
}
