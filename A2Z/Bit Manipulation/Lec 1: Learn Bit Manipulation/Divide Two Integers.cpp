question link:
https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long n = abs((long)dividend);
        long d = abs((long)divisor);

        bool sign = true;
        if (dividend >= 0 and divisor < 0)
            sign = false;
        if (dividend < 0 and divisor >= 0)
            sign = false;

        long cnt = 0;
        while (n >= d) {
            int i = 0, cum = 0;
            while (n >= d << i) {
                i++;
            }
            cnt += 1 << (i - 1);
            n -= d << (i - 1);
        }
        if (cnt == (1 << 31) && sign) {
            return INT_MAX;
        }

        if (cnt == (1 << 31) && !sign) {
            return INT_MIN;
        }
        return sign ? cnt : -cnt;
    }
};
