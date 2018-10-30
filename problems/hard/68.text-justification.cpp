/*
 * 问题描述
 * [68] Text Justification
 *
 * https://leetcode.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (21.29%)
 * Total Accepted:    80.3K
 * Total Submissions: 377.4K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * Given an array of words and a width maxWidth, format the text such that each
 * line has exactly maxWidth characters and is fully (left and right)
 * justified.
 * 
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that each
 * line has exactly maxWidth characters.
 * 
 * Extra spaces between words should be distributed as evenly as possible. If
 * the number of spaces on a line do not divide evenly between words, the empty
 * slots on the left will be assigned more spaces than the slots on the right.
 * 
 * For the last line of text, it should be left justified and no extra space is
 * inserted between words.
 * 
 * Note:
 * 
 * 
 * A word is defined as a character sequence consisting of non-space characters
 * only.
 * Each word's length is guaranteed to be greater than 0 and not exceed
 * maxWidth.
 * The input array words contains at least one word.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * Output:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * Explanation: Note that the last line is "shall be    " instead of "shall
 * be",
 * because the last line must be left-justified instead of fully-justified.
 * ⁠            Note that the second line is also left-justified becase it
 * contains only one word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * Output:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
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
#include <cassert>
using namespace std;

#define pb push_back
#define fst first
#define snd second

using int64 = long long;
using pii = pair<int,int>;
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const int64 MOD=1e9+7;



/*
 * 解决方案
 */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int i = 0;
        int len = 0;
        int start = 0;

        string s;
        s.reserve(maxWidth + 1);
        for(; i < words.size(); i++) {
            assert(words[i].size() <= maxWidth);
            len += words[i].size();
            if(len + (i-start) <= maxWidth) {
                continue;
            }

            len -= words[i].size();
            i--;

            int space = 0;
            int remain = 0;

            if(i - start > 0) {
                space = (maxWidth - len) / (i - start);
                remain = (maxWidth - len) % (i - start);
            }
            else {
                space = maxWidth - len;
            }

            for(int j = start; j <= i; j++) {
                s += words[j];
                if(j == i && j != start) {
                    continue;
                }

                for(int k = 0; k < space; k++) {
                    s.push_back(' ');
                }

                if(remain > 0) {
                    s.push_back(' ');
                    remain--;
                }
            }

            ans.push_back(s);

            len = 0;
            start = i + 1;
            s.clear();
        }

        for(i = start; i < words.size(); i++) {
            s += words[i];
            s += " ";
        }

        if(!s.empty()) {
            if(s.size() > maxWidth) {
                s.pop_back();
            }
            else {
                for(int j = s.size(); j < maxWidth; j++) {
                    s.push_back(' ');
                }
            }
            ans.push_back(s);
        }

        return ans;
    }
};
