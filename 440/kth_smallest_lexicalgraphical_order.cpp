/*
 *Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 10^9.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
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
 * 1. 10叉树的先序遍历.
 * 2. 可根据确定性优化，
 * 3. 递归
 */

class Solution {
    public:
        int findKthNumber(int n, int k) {
            vector<int> num{0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111};

            int prefix = 0;
            int c = 1;
            int a = n;
            while(a /= 10) {
                c++;
            }

            int first = 1;
            while (k) {
                /*
                if(c == 1) {
                    prefix = prefix * 10 + k - 1 + first;
                    return prefix;
                }
                */

                int l = n - num[c-1] * (10 - first);
                int m = l / (num[c] - num[c-1]);
                int r = l - m * (num[c] - num[c-1]);
                int p = 0;

                //cout << n << ":n " << k << ":k " << c << ":c " << m << ":m" << endl;

                if(num[c] * m >= k) {
                    p = (k - 1) / num[c];
                    k = (k - 1)  % num[c] + 1;
                    n = num[c]; 
                }
                else if((num[c-1] * (9 - m - first)) > (n - k)) {
                    p = 9 - ((n - k) / num[c-1]) - first;
                    k = num[c-1] - (n - k) % num[c-1];
                    n = num[c-1];
                }
                else {
                    p = m;
                    k -= m * num[c];
                    n = r + num[c-1];
                }

                prefix = prefix * 10 + p + first;
                //cout << "\t" << p << ":p " << k << ":k " << prefix << ":prefix" << endl;

                if(k == 1) {
                    return prefix;
                }

                c--;
                k--;
                n--;

                first = 0;
            }

            return prefix;
        }
};


/*
class Solution {
public:
    int findKthNumber(int n, int k) {
        stack<int> s;
        map<int, bool> flag;

        if(k == 1) {
            return 1;
        }

        s.push(1);
        flag[1] = false;

        int cnt = 1;
        while(!s.empty()) {
            int c = s.top();

            if(flag[c]) {
                s.pop();
                c += 1;
                if(c % 10 == 0) {
                    continue;
                }
            }
            else {
                flag[c] = true;
                c *= 10;
            }

            if(c > n) {
                continue;
            }

            s.push(c);
            flag[c] = false;
            cnt++;
            if(cnt == k) {
                return c;
            }
        }

        return 1;
    }
};
*/

int main(int argc, const char *argv[])
{
    Solution s;
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << s.findKthNumber(a, b) << endl;
    return 0;
}
