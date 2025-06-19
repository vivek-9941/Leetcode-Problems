class Solution {
    double pos(double x, int n) {
        if (n == 0)
            return 1.0;
        double half = pos(x, n / 2);

        if (n % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }

    public double myPow(double x, int n) {
          if (n < 0) {
            // Use long to avoid overflow when n == Integer.MIN_VALUE
            long ln = -(long)n;
            return 1.0 / pos(x, (int)ln);
        }

        return pos(x, n);
    }
}