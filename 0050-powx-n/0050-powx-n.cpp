class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long N = n;
        if (N < 0) {
            N = -N;
            x = 1 / x;
        }
        double res = 1;
        while (N > 0) {
            if (N % 2 == 1) res *= x;
            x *= x;
            N /= 2;
        }
        return res;
    }
};