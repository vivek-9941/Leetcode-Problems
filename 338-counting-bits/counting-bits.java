class Solution {
    int  calculate(int n ){
        int cnt = 0;

        while(n>0){
           cnt+= n & 1;
            n =n >> 1;
        }
        return cnt;
    }
    public int[] countBits(int n) {
        int arr[]  = new int[n+1];
        for(int i = 0; i <= n ;i++) {
            arr[i] = calculate(i);
        }
        return arr;
    }
}