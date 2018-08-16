/*
 *A robot on an infinite grid starts at point (0, 0) and faces north.  The robot can receive one of three possible types of commands:

-2: turn left 90 degrees
-1: turn right 90 degrees
1 <= x <= 9: move forward x units
Some of the grid squares are obstacles. 

The i-th obstacle is at grid point (obstacles[i][0], obstacles[i][1])

If the robot would try to move onto them, the robot stays on the previous grid square instead (but still continues following the rest of the route.)

Return the square of the maximum Euclidean distance that the robot will be from the origin.

 

Example 1:

Input: commands = [4,-1,3], obstacles = []
Output: 25
Explanation: robot will go to (3, 4)
Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
Output: 65
Explanation: robot will be stuck at (1, 4) before turning left and going to (1, 8)
 

Note:

0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
The answer is guaranteed to be less than 2 ^ 31.
 */

#include <vector>
#include <unordered_set>
using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

#define HASH(x, y) (((unsigned long long)(x) << 32) | (unsigned int)(y))

class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
        unordered_set<unsigned long long> obs_set;
        for(const auto & a: obstacles) {
            obs_set.insert(HASH(a[0], a[1]));
        }

        int max = 0;
        int x = 0;
        int y = 0;
        
        int* axis[] = {&y, &x, &y, &x};
        int diff[] = {1, 1, -1, -1};
        int direct = 0;

        for (const auto&c: commands) {
            if(c < 0) {
                // Turning left and turning right are opposite actions, it's good to be -1 and 1.
                direct += ((c + 1) << 1) + 1;
                direct &= 3;
                continue;
            }

            int &a = *axis[direct];
            int d = diff[direct];

            for(int i = 0; i < c; i++) {
                a += d;
                if (obs_set.end() != obs_set.find(HASH(x, y))) {
                    a -= d;
                    break;
                }
            }

            int distance = x * x + y * y;
            if(max < distance) {
                max = distance;
            }
        }

        return max;
    }
};

int main(int argc, const char *argv[])
{
    Solution s;
    vector<int> commands{2, -1, 8, -1, 6};
    vector<vector<int> > obstacles{{1,5},{-5,-5},{0,4},{-1,-1},{4,5},{-5,-3},{-2,1},{-2,-5},{0,5},{0,-1}};
    s.robotSim(commands, obstacles);
    return 0;
}
