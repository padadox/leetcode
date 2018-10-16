// 20181015 11:38
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


/**
 *4. Median of Two Sorted Arrays
DescriptionHintsSubmissionsDiscussSolution
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
 */

/*
 * 二分查找。
 * 每个数组分别分成两部分，A1, A2, B1, B2
 * ∀a ∈ (A1+A2), ∀b ∈ (B1+B2), a <= b 
 * 对A1的size做二分查找。
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;
        int middle = 0;
        int another = 0;
        while(low <= high) {
            middle = (low + high) / 2;
            another = (m + n) / 2 - middle;

            if(another > n) {
                low = middle + 1;
                continue;
            }

            if(another < 0) {
                high = middle - 1;
                continue;
            }

            if(middle >= m) {
                break;
            }

            if(another < n && middle > 0 && nums1[middle-1] > nums2[another]) {
                high = middle - 1;
            }
            else if(middle < m && another > 0 && nums2[another-1] > nums1[middle]) {
                low = middle + 1;
            }

            break;
        }

        int next = 0;
        int cur = 0;
        if(middle == m) {
            next = nums2[another];
        }
        else if(another == n) {
            next = nums1[middle];
        }
        else {
            next = min(nums1[middle], nums2[another]);
        }

        if(((m + n) & 1) == 0) {
            if(middle == 0) {
                cur = nums2[another-1];
            }
            else if(another == 0) {
                cur = nums1[middle-1];
            }
            else {
                cur = max(nums1[middle-1], nums2[another-1]);
            }
        }

        double ans = 0;
        if((m + n) & 1) {
            ans = next;
        }
        else {
            ans = (cur + next) / 2.0;
        }

        return ans;
    }
};

inline void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
                }));
}

inline void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
                }).base(), input.end());
}

inline vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main(int argc, const char *argv[])
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    vector<int> nums1 = stringToIntegerVector(s1);
    vector<int> nums2 = stringToIntegerVector(s2);

    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

