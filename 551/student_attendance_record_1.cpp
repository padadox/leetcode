/*
 *You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
 */

#include <string>
using namespace std;

class Solution {
    public:
        bool checkRecord(string s) {

            int a = 0;
            int c_l = 0;

            for (char c: s) {
                if(c == 'L') {
                    c_l++;

                    if (c_l > 2) {
                        return false;
                    }

                    continue;
                }

                c_l = 0;

                if (c == 'A') {
                    a++;

                    if(a > 1) {
                        return false;
                    }
                }
            }

            return true;
        }

};
