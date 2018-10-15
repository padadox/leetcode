#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int starsMatched = 0;
        int Lefts = 0;
        int starsLeft = 0;
        for (unsigned i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                Lefts++;
            }
            else if (s[i] == ')') {
                // If there is a left parenthesis available, match with this right parenth
                if (Lefts) {
                    Lefts--;
                }
                // If no more left parenth available, check if any open stars to match with
                else if (starsLeft){
                    starsLeft--;
                }
                // If no more stars to match with, match with any stars matched with earlier left parenth
                else if(starsMatched) {
                    starsMatched--;
                    starsLeft++;
                }
                else {
                    return false;
                }
            }
            else {
                // If no more lefts available, increase num of available stars
                if (!Lefts) {
                    starsLeft++;
                }
                // Otherwise match with left and keep track of this match
                else {
                    starsMatched++;
                    Lefts--;
                }
            }
        }
        return !Lefts;
    }
};
