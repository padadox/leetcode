// 20181005 16:23
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


/*
   You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

   Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
*/

/*
 * 方法1：
 *  DP
 * 方法2：
 * 遍历
 * DP的Key较复杂，可能反而没有遍历快。
 */

class Solution {
    float precision = 1. / (6 * 7 * 8 * 9);
    map<vector<int>, unordered_set<float>> result;
    public:
    bool judgePoint24(vector<int>& nums) {

        auto res = cal(nums);
        for(auto x: res) {
            if((x - precision) < 24 && (x + precision) > 24) {
                return true;
            }
        }

        return false;
    }

    const unordered_set<float>& cal(vector<int>& nums) {
        vector<int> hash;
        hash = nums;
        sort(hash.begin(), hash.end());
        auto it = result.find(hash);
        if(it != result.end()) {
            return result[hash];
        }


        unordered_set<float> ans;
        if(nums.size() == 1) {
            ans.insert(nums[0]);
            result[hash] = ans;
            return result[hash];
        }

        for(int len = 1; len <= nums.size() / 2; len++) {
            for(int i = 0; i < nums.size(); i++) {
                for(int j = i + 1; j <= nums.size() - (len-1); j++) {
                    vector<int> left;
                    vector<int> right;

                    left.push_back(nums[i]);
                    right = nums;
                    if(len == 2) {
                        left.push_back(nums[j]);
                        right.erase(right.begin() + j);
                    }

                    right.erase(right.begin() + i);

                    auto res_left = cal(left);
                    auto res_right = cal(right);

                    for(auto x: res_left) {
                        for(auto y: res_right) {
                            ans.insert(x + y);
                            ans.insert(x - y);
                            ans.insert(x * y);
                            if((y + precision < 0) || (y - precision > 0)) {
                                ans.insert(x * 1. / y);
                            }
                        }
                    }

                    if(1 == len) {
                        break;
                    }
                }
            }
        }

        result[hash] = ans;
        return result[hash];
    }
};

int main(int argc, const char *argv[])
{
    vector<int> nums(4, 0);
    cin >> nums[0];
    cin >> nums[1];
    cin >> nums[2];
    cin >> nums[3];

    cout << Solution().judgePoint24(nums) << endl;

    return 0;
}

/*
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            if(valid(nums)) return true;
        }while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
    
    bool valid(vector<int> &nums){
        double a=nums[0], b=nums[1], c=nums[2], d=nums[3];
        if(valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d))    return true;
        if(valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d))    return true;
        if(valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d))    return true;
        return false;
    }
    
    bool valid(double a, double b, double c){
        if(valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c))   return true;
        if(valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c))   return true;
        return false;
    }
    
    bool valid(double a, double b){
        if(abs(a+b-24.0)<0.0001 || abs(a-b-24.0)<0.0001 || abs(a*b-24.0)<0.0001 || b&&abs(a/b-24.0)<0.0001)
            return true;
        return false;
    }
};
*/
