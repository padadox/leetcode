/*
You have a list of words and a pattern, and you want to know which words in words matches the pattern.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern. 

You may return the answer in any order.

 

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
 

Note:

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p_hash = hash(pattern);
        vector<string> result;
        result.reserve(words.size());

        for(auto& w: words) {
            string x = hash(w);
            if(x == p_hash) {
                result.push_back(w);
            }
        }

        return result;
    }

    string hash(string & s) {
        int serial[26] = {0};

        string hash = s;
        int cnt = 0;
        for(size_t i = 0; i < s.size(); ++i) {
            char c = s[i] - 'a';
            if(serial[c] == 0) {
                cnt++;
                serial[c] = cnt;
            }

            hash[i] = 'a' -1 + serial[c];
        }

        return hash;
    }
};

