/*
 *Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

#define MAX_WORD_SIZE 38

typedef unsigned long long hash_type;
typedef vector<vector<string> > store_type;

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            store_type result;
            vector<hash_type> hash_values;
            hash(strs, hash_values);
            split(strs, hash_values, result);

            return result;
        }

        // 算法：
        // 将N个相同的球，放进M个不同的盒子，盒子可以为空，共有（N+M-1, M-1)种方法。
        // 转化为将N+M个相同的球，放进M个不同盒子，盒子不可以为空的问题，使用插板法解决：
        // N+M-1个间隙，插入M-1个隔板
        // 用bit位为1表示插板，64bit可以表示64+1-26=39个字符的单词。
        // 超过39个字母的单词未特殊处理，有概率误分, 可能误分到39个字母的集合，但不会影响39个以下的集合。
        // 因此, 如支持任意长度，保证正确的最大长度为38, 其余存在误分概率；如限定超过长度另外处理，能支持的最大长度为39

        hash_type hashword(const string& s)
        {
            const char *p = s.c_str();
            char n['z'-'a'+1] = {0};

            assert(s.size() <= MAX_WORD_SIZE);

            hash_type value = 0;
            for (char c = 0; (c = *p); p++)
            {
                c = c | 0x20; // to lower

                if (c < 'a' || c > 'z')
                {
                    continue;   // not a letter
                }

                c = c - 'a';
                n[(int)c]++;
            }

            value = (hash_type)-1;

            size_t cnt = 0;
            hash_type init_mask = (hash_type)-1;
            for(size_t j = 0; j < sizeof(n) / sizeof(*n); ++j)
            {
                if (0 == n[j])
                {
                    continue;
                }

                size_t shift = cnt + j;
                hash_type mask = 0;

                if (shift < sizeof(init_mask) * 8)
                {
                    mask = init_mask << (cnt + j);
                }
                else
                {
                    mask = 0;
                }
                hash_type v1 = value & (~mask);
                hash_type v2 = value & mask;

                v2 <<= n[j];
                value = v1 | v2;

                cnt += n[j];
            }

            return value;
        }

        int hash(const vector<string>& words, vector<hash_type> &values)
        {
            values.reserve(words.size());

            for (size_t i = 0; i < words.size(); i++)
            {
                values.push_back(hashword(words[i]));
            }

            return 0;
        }

        int split(const vector<string>& words, const vector<hash_type>& values, store_type& anagrams)
        {
            unordered_map<hash_type, int> pack;
            anagrams.reserve(words.size());

            for (size_t i = 0; i < words.size(); i++)
            {
                const hash_type &value = values[i];

                if (pack.end() == pack.find(value))
                {
                    anagrams.push_back(store_type::value_type());
                    pack[value] = anagrams.size()-1;
                }

                store_type::value_type& v = anagrams[pack[value]];
                v.push_back(words[i]);
            }

            return 0;
        }
};

int main() {
    Solution s;
    vector<string> words{"eat","tea","tan","ate","nat","bat"};

    vector<vector<string> > r = s.groupAnagrams(words);
}
