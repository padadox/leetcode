// 20181016 18:27
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
 *Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Note:

S.length <= 100
33 <= S[i].ASCIIcode <= 122 
S doesn't contain \ or "
 */

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        int i = -1;
        int j = n;

        while(i < j) {
            for(i++; i < j && !isalpha(S[i]); ++i);
            for(j--; j > i && !isalpha(S[j]); --j);
            if(i >= j) {
                break;
            }

            swap(S[i], S[j]);
        }

        return S;
    }
};

int main(int argc, const char *argv[])
{
    string S;
    cin >> S;
    cout << Solution().reverseOnlyLetters(S) << endl;
    return 0;
}
