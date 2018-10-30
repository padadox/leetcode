/*
 * 问题描述
 * [964] Minimize Malware Spread II
 *
 * https://leetcode.com/problems/minimize-malware-spread-ii/description/
 *
 * algorithms
 * Hard (35.62%)
 * Total Accepted:    1.5K
 * Total Submissions: 4K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]\n[0,1]'
 *
 * (This problem is the same as Minimize Malware Spread, with the differences
 * bolded.)
 * 
 * In a network of nodes, each node i is directly connected to another node j
 * if and only if graph[i][j] = 1.
 * 
 * Some nodes initial are initially infected by malware.  Whenever two nodes
 * are directly connected and at least one of those two nodes is infected by
 * malware, both nodes will be infected by malware.  This spread of malware
 * will continue until no more nodes can be infected in this manner.
 * 
 * Suppose M(initial) is the final number of nodes infected with malware in the
 * entire network, after the spread of malware stops.
 * 
 * We will remove one node from the initial list, completely removing it and
 * any connections from this node to any other node.  Return the node that if
 * removed, would minimize M(initial).  If multiple nodes could be removed to
 * minimize M(initial), return such a node with the smallest index.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
 * Output: 0
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
 * Output: 1
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 < graph.length = graph[0].length <= 300
 * 0 <= graph[i][j] == graph[j][i] <= 1
 * graph[i][i] = 1
 * 1 <= initial.length < graph.length
 * 0 <= initial[i] < graph.length
 * 
 * 
 * 
 * 
 * 
 */


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

using int64 = long long;
using pii = pair<int,int>;
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const int64 MOD=1e9+7;



static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();




/*
 * 解决方案
 * 方法1：
 * 从每一个初始感染点出发，搜索所有不经过其他初始感染点，可被达到的点，记录其感染源为当前初始感染点，如果该点已被感染过，则感染源置为特殊标记。
 * 方法2：
 * 从非初始感染点出发，搜索所有不经过初始感染点，可被达到的点。记录能到达的感染点及数目。
 * (此方法为submission中效率最高的方法之一。感觉对沙漏型图存疑，沙漏核心点为感染点，在搜索子图时有问题）)
 */

/*
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        static const int UNMALED = -1;
        static const int INITIAL = numeric_limits<int>::max()-1;
        static const int MULTI = numeric_limits<int>::max();
        vector<int> flag(n, UNMALED);
        vector<int> d(initial.size(), 0);

        for(auto x: initial) {
            flag[x] = INITIAL;
        }

        for(int i = 0; i < initial.size(); i++) {
            int x = initial[i];

            queue<int> q;
            q.push(x);

            while(!q.empty()) {
                int m = q.front();
                q.pop();
                for(int j = 0; j < graph[m].size(); j++) {
                    if(!graph[m][j]) {
                        continue;
                    }

                    if(flag[j] >= n || flag[j] == i) {
                        continue;
                    }

                    if(flag[j] == UNMALED) {
                        flag[j] = i;
                    }
                    else {
                        flag[j] = MULTI;
                    }
                    q.push(j);
                }
            }
        }

        for(auto f: flag) {
            if(f >= n || f == UNMALED) {
                continue;
            }

            d[f]++;
        }

        int ans = initial[0];
        int max = d[0];
        for(int i = 0; i < d.size(); i++) {
            if(d[i] > max) {
                max = d[i];
                ans = initial[i];
            }
            else if(d[i] == max && ans > initial[i]) {
                ans = initial[i];
            }
        }

        return ans;
    }
};
*/

class Solution {
public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int max_node = *min_element(begin(initial),end(initial)), max_count = 0;
    const auto node_count = graph.size();
    vector<bool> infected(node_count,false);
    vector<bool> visited(node_count,false);
    for(auto index: initial) {
      infected[index] = true;
    }
    vector<int> subgraph;
    subgraph.reserve(node_count);
    vector<int> infect_count(graph.size(), 0);

    for(auto node = 0; node < node_count; node++) {
      if(infected[node] || visited[node]) {
        continue;
      }
      subgraph.push_back(node);
      visited[node] = true;
      auto current_count = 1,infected_count = 0, infected_node = -1;
      while(!subgraph.empty()) {
        auto current_node = subgraph.back();
        subgraph.pop_back();
        const auto& connections = graph[current_node];
        for(auto other = 0; other < node_count; other++) {
          if(!visited[other] && connections[other]) {
            if(infected[other]) {
              if(other != infected_node) {
                infected_count++;
                infected_node = other;
              }
            } else {
              visited[other] = true;
              current_count++;
              subgraph.push_back(other);
            }
          }
        }
      } //end while stack not empty
      if(infected_count == 1) {
          infect_count[infected_node] += current_count;
      }
    } //end for all nodes

    auto it = max_element(infect_count.begin(), infect_count.end());
    if(*it == 0) {
        return *min_element(initial.begin(), initial.end());
    }
    return distance(infect_count.begin(), it);
  }
};

