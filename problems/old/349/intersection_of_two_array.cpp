/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
 *
 * */

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

/*
 * Answer is wrong when use unordered set and set_intersection. Because set_intersection work on sorted values.
 */

typedef unordered_set<int> set_type;


class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            set_type s1;
            set_type result;

            s1.insert(nums1.begin(), nums1.end());
            
            for(size_t i = 0; i < nums2.size(); ++i) {
                if(s1.end() != s1.find(nums2[i])) {
                    result.insert(nums2[i]);
                }
            }

            vector<int> r;
            r.insert(r.begin(), result.begin(), result.end());

            return r;
        }
};

int main() {
    vector<int> v1{4, 9, 5};
    vector<int> v2{9, 4, 9, 8, 4};

    Solution s;

    vector<int> r = s.intersection(v1, v2);

    for(size_t i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }

    cout << endl;
}

