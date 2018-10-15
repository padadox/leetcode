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
 405. Convert a Number to Hexadecimal
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"*
 */

class Solution {
public:
    string toHex(int num) {
        if(num == 0) {
            return "0";
        }

        string ans;
        ans.reserve(8);
        unsigned int n = (unsigned int)num;

        char hex[16] = {'0', '1','2','3','4','5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

        for(int i = 7; i >= 0; i--) {
            unsigned char c = (unsigned char)((n >> (4 * i)) & 0x0f);
            if(c == 0 && ans.size() == 0) {
                continue;
            }

            ans.push_back(hex[c]);
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    int n = 26;
    cin >> n;
    cout << Solution().toHex(n) << endl;
    
    return 0;
}
