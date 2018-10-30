/*
 * 问题描述
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (34.59%)
 * Total Accepted:    138.3K
 * Total Submissions: 399.6K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
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



/*
 * 解决方案
 * DP
 * 出错的地方：
 * 1、必要数据的初始化
 * 2、word1[i] == word2[j] 时，计算了删除和添加情况，无必要。
 *
 * 总起来看，就是分析问题不明确清晰。
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() || word2.empty()) {
            return word1.size() + word2.size();
        }

        int m = word1.size();
        int n = word2.size();
        int distance[m+1][n+1] = {0};

        for(int i = 0; i < m; i++) {
            distance[i+1][0] = i+1;
        }

        for(int j = 0; j < n; j++) {
            distance[0][j+1] = j+1;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(word1[i] == word2[j]) {
                    distance[i+1][j+1] = distance[i][j];
                }
                else {
                    distance[i+1][j+1] = min(min(distance[i][j], distance[i][j+1]), distance[i+1][j]) + 1;
                }
            }
        }

        return distance[m][n];
    }
};


static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


