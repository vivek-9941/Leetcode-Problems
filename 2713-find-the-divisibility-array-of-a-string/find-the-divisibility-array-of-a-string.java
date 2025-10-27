class Solution {
    public int[] divisibilityArray(String word, int m) {
        int n = word.length();
        int arr[] = new int[n];
        long num = 0; // use long to store running modulo value safely

        for (int i = 0; i < n; i++) {
            int digit = word.charAt(i) - '0';
            num = (num * 10 + digit) % m; // build the number gradually using modulo

            if (num == 0)
                arr[i] = 1;
            else
                arr[i] = 0;
        }

        return arr;
    }
}
