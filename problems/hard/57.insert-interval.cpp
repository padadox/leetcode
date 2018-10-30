/*
 * 问题描述
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (29.91%)
 * Total Accepted:    147.3K
 * Total Submissions: 492.2K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
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
 * 二分查找。
 * 注意：
 * newInteval的start同已有数据的end比较，end同start比较。
 * upper_bound和lower_bound的cmp函数, 前者第一个参数为val, 后者第二个参数为val, 因为有是否包含equal的差异。
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       auto b = lower_bound(intervals.begin(), intervals.end(), newInterval,
               [](const auto& a, const auto& b) -> bool {
                    return a.end < b.start;
               });

       auto e = upper_bound(b, intervals.end(), newInterval, 
               [](const auto& a, const auto& b) -> bool {
                    return a.end < b.start;
               });

       if(b == e) {
           intervals.insert(b, newInterval);
       }
       else {
           b->start = min(b->start, newInterval.start);
           b->end = max((e-1)->end, newInterval.end);
           intervals.erase(b+1, e);
       }

       return intervals;
    }
};



static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



/*
int main(int argc, const char *argv[])
{
    vector<Interval> x {{1, 3}, {6, 9}};
    Interval y{2, 5};

    Solution().insert(x, y);

    return 0;
}
*/
