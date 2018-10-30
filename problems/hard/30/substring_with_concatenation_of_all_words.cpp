// 20181017 20:02
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



/**
 * 问题描述
 *

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
Output: []
 */

/**
 * 解决方案
 * 直接搜索。
 *
 */

class Solution {
    int word_len = 0;

public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.empty()) {
            return ans;
        }

        word_len = words[0].size();

        if(word_len == 0) {
            return ans; 
        }

        unordered_map<string, pair<int, int>> ws;
        for(auto &x: words) {
            auto it = ws.find(x);
            if(it == ws.end()) {
                ws[x] = make_pair(1, 0);
            }
            else {
                it->second.first++;
            }
        }


        for(int i = 0; i <= (int)s.size() - word_len * (int)words.size(); i++) {
            if(search(s, i, ws, words.size())) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool search(const string& s, int start, unordered_map<string, pair<int, int>> &ws, int target_cnt) {
        if(target_cnt == 0) {
            return true;
        }

        if(start >= s.size()) {
            return false;
        }

        string w = s.substr(static_cast<size_t>(start), static_cast<size_t>(word_len));
        auto it = ws.find(w);
        if(it == ws.end()) {
            return false;
        }

        if(it->second.first <= it->second.second) {
            return false;
        }

        it->second.second++;

        bool ret = search(s, start + word_len, ws, target_cnt-1);
        it->second.second--;

        return ret;
    }
};

#include "../../../utils/utils.hxx"

int main(int argc, const char *argv[])
{
    while(true) {
        string s;
        cin >> s;
        if(s == "q") {
            break;
        }

        vector<string> words;
        while(true) {
            string tmp;
            cin >> tmp;
            if(tmp == "q") {
                break;
            }

            words.push_back(tmp);
        }

        printIntegerVector(Solution().findSubstring(s, words));
    }
    return 0;
}
