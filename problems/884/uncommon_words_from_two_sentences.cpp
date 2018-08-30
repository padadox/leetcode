/*
 *We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
 */

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> a_words;
        unordered_map<string, int> b_words;

        get_words(A, a_words);
        get_words(B, b_words);

        vector<string> result;
        for(auto &w: a_words) {
            string word = w.first;
            int cnt = w.second;
            if(cnt > 1) {
                continue;
            }

            if(b_words.end() == b_words.find(word)) {
                result.push_back(word);
            }
        }

        for(auto &w: b_words) {
            string word = w.first;
            int cnt = w.second;
            if(cnt > 1) {
                continue;
            }

            if(a_words.end() == a_words.find(word)) {
                result.push_back(word);
            }
        }
        return result;
    }

    void get_words(const string &s, unordered_map<string, int>& words) {
        size_t start = 0;
        size_t end = 0;

        while(true) {
            end = s.find(' ', start);
            string word = s.substr(start, end - start);
            words[word]++;
            if(end == string::npos) {
                break;
            }

            start = end + 1;
        }
    }
};

int main(int argc, const char *argv[])
{
    string A = "this apple is sweet";
    string B = "this apple is sour";

    Solution s;
    s.uncommonFromSentences(A, B);
    
    return 0;
}
