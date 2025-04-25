class Solution {
    public int minFlips(int a, int b, int c) {
        int cnt = 0;
        while (c > 0 || a > 0 || b > 0) {
            int bitA = a & 1;
            int bitB = b & 1;
            int bitC = c & 1;
            
            if (bitC == 1) {
                if ((bitA | bitB) == 0) {
                    cnt++;
                }
            } else {
                cnt += bitA + bitB;
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
}

