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
 *In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4]
Example 2:

Input: [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: [1,1]
Output: true
Explanation: Possible partition [1,1]
Example 5:

Input: [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2]

Note:

1 <= deck.length <= 10000
0 <= deck[i] < 10000
 *
 */

/**
 * 方法1：
 *  1、统计每个值出现的个数；
 *  2、找到最小个数；
 *  3、计算最小个数的因子；
 *  4、遍历因子，看因子是否可以被所有个数整除；
 *
 * 方法2:
 *  1、统计每个值出现的个数；
 *  2、计算所有因子的最小公倍数，看是否大于等于2
 *
 */

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;

        for(auto x: deck) {
            if(count.find(x) == count.end()) {
                count[x] = 0;
            }
            count[x]++;
        }

        int min = numeric_limits<int>::max();
        for(auto it = count.begin(); it != count.end(); it++) {
            if(min > it->second) {
                min = it->second;
            }
        }

        vector<int> factor;
        for(int a = 2; a <= min; a++) {
            if(min % a == 0) {
                factor.push_back(a);
            }
        }

        for(auto x: factor) {
            auto it = count.begin();
            for(; it != count.end(); it++) {
                if(it->second % x != 0) {
                    break;
                }
            }

            if(it == count.end()) {
                return true;
            }
        }

        return false;
    }
};

