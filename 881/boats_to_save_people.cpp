/*
 *
The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int first = 0;
        int last = people.size();
        int res = 0;

        while (first < last) {
            if(first + 1 == last) {
                res++;
                break;
            }

            int v = people[first];
            first++;

            auto up = upper_bound(people.begin() + first, people.begin() + last, limit - v);
            int upper = up - people.begin();
            res += 1 + last - upper;
            last = upper - 1;
        }

        return res;
    }

};

/*
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        auto first = people.begin();
        auto last = people.end();
        int res = 0;

        while (first != last) {
            if(first + 1 == last) {
                res++;
                break;
            }

            int v = *first;
            first++;

            auto upper = upper_bound(first, last, limit - v);
            if(upper == last) {
                res++;
                last--;
                continue;
            }

            res += 1 + last - upper;

            if(upper == first) {
                break;
            }

            last = upper - 1;
        }

        return res;
    }

};
*/
