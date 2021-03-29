
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        // 考虑边缘情况
        if (x == 0 || x == 1.0)
        {
            return x;
        }

        // 考虑溢出的情况
        long b = (long)n;
        if (b < 0)
        {
            b = -b;
            x = 1/x;
        }

        while (b > 0)
        {
            if ((b&1) == 1)
            {
                res *= x;
            }
            x *= x;
            b >>= 1;
        }

        return res;
    }
};
