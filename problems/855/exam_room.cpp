/*
   In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

   When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

   Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.



   Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.

Note:

1 <= N <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

*/

#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
struct Position {
    int idx = 0;
    int left = 0;
    int right = 0;
    int space = 0;
    int valid = false;

    Position() {}

    Position(int i, int j, int k, int s) {
        idx = i;
        left = j;
        right = k;
        space = s;
    }
};

struct Cmp {
    bool operator()(const Position& a, const Position& b) {
        if (a.space == b.space) {
            return a.idx > b.idx;
        }

        return a.space < b.space;
    }
};

class ExamRoom {
    private:
        int N;
        map<int, Position> p;
        priority_queue<Position, vector<Position>, Cmp> q;

    public:
        ExamRoom(int N) {
            this->N = N;
            Position x(0, -1, N, N);
            p[0] = x;
            q.push(x);
        }

        int seat() {
            while(!q.empty()) {
                const Position m = q.top();
                q.pop();

                if(p.end() == p.find(m.idx)) {
                    continue;
                }

                auto& c = p[m.idx];
                if(c.space != m.space) {
                    continue;
                }

                if (c.left != -1) {
                    int left_center = (c.left + c.idx) / 2;
                    if(c.left != left_center) {
                        Position x(left_center, c.left, c.idx, left_center - c.left);
                        p[left_center] = x;
                        q.push(x);

                        p[c.left].right = left_center;
                        c.left = left_center;
                    }
                }

                int right_center = (c.right + c.idx) / 2;
                if(c.right == N) {
                    right_center = N - 1;
                }

                if(right_center != c.idx) {
                    Position x(right_center, c.idx, c.right, right_center - c.idx);
                    p[right_center] = x;
                    q.push(x);

                    p[c.right].left = right_center;
                    c.right = right_center;
                }
                    
                c.space = 0;
                return c.idx;
            }

            return -1;
        }

        void leave(int m) {
            auto &c = p[m];

            c.space = 0;

            auto left = c.left;
            auto right = c.right;


            if(left != -1) {
                auto& l = p[left];
                if(l.space != 0) {
                    left = l.left;
                    p.erase(l.idx);
                }
            }

            if(right != N) {
                auto& r = p[right];
                if(r.space != 0) {
                    right = r.right;
                    p.erase(r.idx);
                }
            }

            p.erase(c.idx);

            int idx = 0;
            int space = 0;
            if(left == -1) {
                idx = 0;
                space = right - idx;
            }
            else if(right == N) {
                idx = N-1;
                space = idx - left;
            }
            else {
                idx = (right + left) / 2;
                space = idx - left;
            }

            if(left != -1) {
                p[left].right = idx;
            }

            if(right != N) {
                p[right].left = idx;
            }

            Position x(idx, left, right, space);
            p[idx] = x;
            q.push(x);

            return;
        }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */

int main() {
    ExamRoom s(9);
    s.seat();
    s.seat();
    s.seat();
    s.seat();
    s.leave(4);
    s.seat();
    s.seat();
    s.seat();
    s.seat();
    s.seat();
    s.seat();
    s.leave(3);
    s.seat();
}
