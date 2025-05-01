class Solution {
    public int numSub(String s) {
        int prev = -1;
        long sum = 0;  // Use long to prevent integer overflow
        final int MOD = 1_000_000_007;

        for (int i = 0; i < s.length(); i++) {
            long cnt = 0;
            if (prev == -1 && s.charAt(i) == '1') prev = i;
            if (s.charAt(i) == '0' && prev != -1) {
                cnt = (long) (i - prev) * (i - prev + 1) / 2;
                prev = -1;  
            }
            sum = (sum + cnt) % MOD;
        }

        // Handle remaining trailing '1's if any
        if (prev != -1) {
            long cnt = (long) (s.length() - prev) * (s.length() - prev + 1) / 2;
            sum = (sum + cnt) % MOD;
        }

        return (int) sum;
    }
}
