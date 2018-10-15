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
 *
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
 */

class Solution {
    map<pair<int, int>, vector<string>> parts;
    string s;
    int size;
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;
        res.reserve(256);
        for(int i = 1; i < 4; i++) {
            for(int j = 1; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    int m = n - i - j - k;
                    if(m >= 4 || m < 1) {
                        continue;
                    }

                    string s1 = s.substr(0, i);
                    string s2 = s.substr(i, j);
                    string s3 = s.substr(i+j, k);
                    string s4 = s.substr(i+j+k);
                    if(!valid(s1) || !valid(s2) || !valid(s3) || !valid(s4)) {
                        continue;
                    }

                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }

        return res;
    }

    bool valid(const string &s) {
        int n = s.size();
        if(n > 1 && s[0] == '0') {
            return false;
        }

        int a = atoi(s.c_str());
        if(a > 255) {
            return false;
        }

        return true;
    }
};

