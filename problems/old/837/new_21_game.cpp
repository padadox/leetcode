/*
Alice plays the following game, loosely based on the card game "21".

Alice starts with 0 points, and draws numbers while she has less than K points.  During each draw, she gains an integer number of points randomly from the range [1, W], where W is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets K or more points.  What is the probability that she has N or less points?

Example 1:

Input: N = 10, K = 1, W = 10
Output: 1.00000
Explanation:  Alice gets a single card, then stops.
Example 2:

Input: N = 6, K = 1, W = 10
Output: 0.60000
Explanation:  Alice gets a single card, then stops.
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
Example 3:

Input: N = 21, K = 17, W = 10
Output: 0.73278
Note:

0 <= K <= N <= 10000
1 <= W <= 10000
Answers will be accepted as correct if they are within 10^-5 of the correct answer.
The judging time limit has been reduced for this question.
 */

/*
 * Sln1: DP
 * Denote f(N, K) as the result, f(N, K) = $\frac{1}{W}$ * $\sum_{n=1}^{W}f(N-n, K-n)$
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        double new21Game(int N, int K, int W) {
            if (K <= 0) {
                return 1;
            }

            if(K + W - 1 <= N) {
                return 1;
            }

            vector<double> p(K+1, 0.);
            p[0] = 1.;
            p[1] = min((N - K + 1), W) * 1. / W;

            int window_len = 1;
            double window_sum = p[1];
            for (int k = 2; k <= K; k++) {
                if(k <= W) {
                    p[k] = (min(N-K+k, W) - k + 1) * 1. / W;
                }

                p[k] += 1. / W * window_sum;

                window_sum += p[k];
                window_len++;

                if(window_len > W) {
                    window_sum -= p[k-W];
                    window_len--;
                }
            }

            return p[K];
        }
};

/*
 * Sln2: Combinatorial Problem.
 * Consider n in [K-W, K-W+1, ..., K-1], which can stop drawing process after one drawing.
 * The probability to reach n is:
 * $P_1 = \sum_{m=\left\lceil\frac{n}{W}\right\rceil}^{n}\frac{1}{W^m}C_{n-1}^{m-1} $
 * The probability with a draw to n, the result number is less than or equal to N:
 * P = P1 * (N-K+1) / (W-(K-n)+1)
 * O(K*W) time, O(1) space.
 * 
 */

/*
 * WRONG!
#include <cmath>

class Solution {
    public:
    double new21Game(int N, int K, int W) {
        if (K <= 0) {
            return 1;
        }

        // if(K + W - 1 <= N) {
        //     return 1;
        // }

        int s = K - W;
        if (s < 0) {
            s = 0;
        }

        double r = 0.;

        for(int n = s; n < K; ++n) {
            int c = (n + W - 1) / W;
            double factor = 1.0 / pow(W, c);
            unsigned long long comb = combinatorial(n-1, c-1);
            double p = factor * comb;

            for(int m = c + 1; m <= n; ++m) {
                factor = factor / W;
                comb = comb / (m - 1) * (n - m + 1);
                p += factor * comb;
            }

            int x = n + W;
            if (x > N) {
                x = N;
            }
            x = x - K + 1;
            p = p * x / W;
            r += p;
        }

        return r;
    }

    unsigned long long combinatorial(int n, int m) {
        if(n <= 1) {
            return 1;
        }

        if(m < (n - m)) {
            m = n - m;
        }

        unsigned long long r = 1;
        for(int i = n; i > m; --i) {
            r *= i;
        }

        for(int i = n-m; i > 0; --i) {
            r /= i;
        }

        return r;
    }
};

#include <iostream>
using namespace std;

int main() {
    Solution s;
    cout << s.new21Game(5, 5, 2) << endl;
}

*/
