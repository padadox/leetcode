/*
 *
 Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*/

/*
 * DFS
 */

#include <string>
#include <vector>
using namespace std;

struct Star {
    int cnt = 0;
    int idx = 0;
};

class Solution {
public:
    bool checkValidString(string s) {
        vector<Star> star;

        star.resize(s.size());
        int c = 0;
        int star_idx = -1;
        size_t last = 0;
        for(;;) {
            for(size_t i = last; i < s.size(); i++) {
                if(s[i] == '*') {
                    star_idx++;
                    star[star_idx].cnt = c;
                    star[star_idx].idx = i;
                    s[i] = '0';
                }

                if(s[i] == '0') {
                    continue;
                }

                if(s[i] == '(') {
                    c++;
                }

                if(s[i] == ')') {
                    c--;
                    if(c < 0) {
                        break;
                    }
                }
            }

            if(c == 0) {
                return true;
            }

            while(1) {
                if(star_idx < 0) {
                    return false;
                }

                c = star[star_idx].cnt;
                last = star[star_idx].idx;

                if(s[last] == ')') {
                    s[last] = '*';
                    star_idx--;
                    continue;
                }

                if(s[last] == '0') {
                    s[last] = '(';
                }
                else if(s[last] == '(') {
                    s[last] = ')';
                }

                break;
            }
        }

        return true;
    }
};
