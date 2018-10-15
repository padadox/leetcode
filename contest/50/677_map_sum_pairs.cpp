// 20181005 14:38
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
 *Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
 *
 *
 */

/**
 * 二分查找
 *
 */

class MapSum {
    vector<pair<string, int>> data;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        auto v = make_pair(key, val);
        auto it = lower_bound(data.begin(), data.end(), v, [](auto &a, auto& b) -> bool {
                    return a.first < b.first;
                });

        if(it == data.end()) {
            data.push_back(v);
            return;
        }

        if(it->first == key) {
            it->second = val;
            return;
        }

        data.insert(it, v);
    }
    
    int sum(string prefix) {
        auto v = make_pair(prefix, 0);
        auto func = [](auto &a, auto& b) -> bool {
                    return a.first < b.first;
                };
        auto begin_it = lower_bound(data.begin(), data.end(), v, func);

        auto end_it = data.end();
        if(!prefix.empty()) {
            string s = prefix;
            s.back()++;
            auto v_end = make_pair(s, 0);
            end_it = lower_bound(begin_it, data.end(), v_end, func);
        }

        int ans = 0;
        for(auto it = begin_it; it != end_it; it++) {
            ans += it->second;
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main(int argc, const char *argv[])
{
    MapSum s;
    s.insert("apple", 2);
    cout << s.sum("ap");
    s.insert("app", 3);
    cout << s.sum("ap");
    return 0;
}
