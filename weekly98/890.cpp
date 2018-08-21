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

