class Solution {
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) return false;

        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) cnt++;
            n = n >> 1;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }
}
