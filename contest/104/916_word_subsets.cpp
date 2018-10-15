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

typedef unsigned long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/*
 *We are given two arrays A and B of words.  Each word is a string of lowercase letters.

Now, say that word b is a subset of word a if every letter in b occurs in a, including multiplicity.  For example, "wrr" is a subset of "warrior", but is not a subset of "world".

Now say a word a from A is universal if for every b in B, b is a subset of a. 

Return a list of all universal words in A.  You can return the words in any order.

 

Example 1:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
Output: ["apple","google","leetcode"]
Example 3:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
Output: ["facebook","google"]
Example 4:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
Output: ["google","leetcode"]
Example 5:

Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
Output: ["facebook","leetcode"]
 */

/**
 * 方法1:
 *  1、统计B中所有单词，每个字母出现的最大次数；
 *  2、遍历A中单词，如果单词中的所有字母，出现次数大于B中最大次数，则放入答案。
 *
 *  方法2：
 *  1、每个字母按编码为单独的素数；
 *  2、对A、B中的单词，分别按照字母对应素数乘积编码;
 *  3、求B中所有单词编码的最小公倍数；
 *  4、遍历A中单词编码，如果编码是B最小公倍数的倍数，则加入答案。
 *  NOTE: 存在溢出风险；
 */

unsigned long long gcd(unsigned long long m, unsigned long long n) {
    if(n == 0) {
        return m;
    }

    return gcd(n, m % n);
}

unsigned long long lcm(unsigned long long m,  unsigned long long n) {
    return m / gcd(m, n) * n;
} 

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107109, 113};

        vector<unsigned long long> hashA(A.size());
        vector<unsigned long long> hashB(B.size());

        for(int i = 0; i < A.size(); ++i) {
            unsigned long long h = 1;
            for(int j = 0; j < A[i].size(); j++) {
                h *= primes[A[i][j] - 'a'];
            }

            hashA[i] = h;
        }

        for(int i = 0; i < B.size(); ++i) {
            unsigned long long h = 1;
            for(int j = 0; j < B[i].size(); j++) {
                h *= primes[B[i][j] - 'a'];
            }

            hashB[i] = h;
        }

        ll least_common_m = hashB[0];
        for(int i = 0; i < B.size(); i++) {
            least_common_m = lcm(least_common_m, hashB[i]);
        }

        vector<string> ans;
        for(int i = 0; i < A.size(); i++) {
            if(hashA[i] % least_common_m == 0) {
                ans.push_back(A[i]);
            }
        }

        return ans;
    }
};

int main(int argc, const char *argv[])
{
    vector<string> A {"faaapumkvq","amdkqpfijv","qpafqvfkpm","mqfckamqvp","fwapsmokvq","bkfzqamvzp","qckmpfsfva","zbmnfykeyw","pjvmqekfpa","pqekvfmlac","nkvamfpsqc","vafqppqmkh","qhpfmkbvas","mvapkbnqaf","vpiqmfzjak","hunjgeaolc","avkdqlpmft","avskfpmmlq","aecglrhxsg","aapmqkfvlf","mfpakqavap","kavfwqepdm","mytxzbmqma","ozvmspkfaq","zafjmpkqpv","pjmqavfkjf","scvakpcfmq","vpjmfawqke","nfzkpmvaaq","afqmekopva","vpmvpafkqy","xfupkvmqad","aggvkpmbfq","cmpqvxatfk","qkmfpvnamq","utlusqhbfy","oppjejmmcy","wndhvprmoz","kxpsawmvqf","pxsvamnkqf","vfmqlkplah","avppfkqudm","ksyvfpaqgm","fmkhfpdqva","pqlrvxamfk","dfqvimjkap","qpvmfwakxb","rrkfcvqapm","vhqrakfvmp","msqhkfapvw","qpfmktpmav","okzckhugsd","fpxkqdmagv","aqpykvofqm","avaqzpfkwm","kvfpamvqzx","pqfkmvacgm","qvmgftkupa","kelxxnfiei","fkpakvqmau","qkxxamvpfa","kqqmcmfpav","mqafvubkvp","fcikmvxapq","kpnfarmvqs","vpmakfnpiq","avkfwmspqk","pmnfkwvqak","avlfkqpvkm","pymkvfqjpa","qmfkaxpfrv","qkkvffapwm","fcwenlxtla","qhpkvfmyaj","fajhfkpqvm","smvkpsaqzf","fpthakqmxv","tmqfawkjvp","vkyaytqpmf","apmtsqvwfk","nujagbkcqj","qwpfkamvpf","mlvqkmpfal","dduzzxmskv","kjkggnwvar","kqsvpamwxf","apqfwekmmv","mvbfpikeqa","qviknmaifp","sokvapfqbm","mvpqaxfqfk","klfvlqmppa","azqkixfpvm","gtframkvqp","wkspfmavkq","mpafjcvykq","rmpxfqkiav","gyaifdnbli","wwnzulopnh","vpafvcmkaq"};
    vector<string> B{"v","vm","vma","vkq","av","vapmq","fmqk","qam","k","kqmvf","aqpfkv","kmqpfa","fva","mqfa","vamkfq","pa","qpk","qfka","qa","f","pmq","qmk","mk","fpamkv","vk","vpkm","mva","v","kvaf","aqvkmf","qm","v","vapmf","fvk","mp","avkmqf","maf","kfvqm","k","kaq","a","vk","mafp","k","kpa","pfqvm","aq","fa","pqfkav","p","kvfpm","q","kfmqp","a","pvk","q","pfkvqa","vkfamq","vkfmpq","afk","p","kvpam","vkpaq","vkqfap","qk","q","qk","vkamp","ma","v","qvapmk","vmqafk","afqpv","kavfmq","f","pvma","paqvmk","v","amqkv","mkpfv","pkmv","mkqvpf","q","vm","v","mfav","fm","f","pmfvq","qk","fpqmk","pamfv","fv","pv","apfmvq","qv","v","kvm","pvmaq","fvp"};

    Solution().wordSubsets(A, B);
    return 0;
}
