class Solution {
    public String[] divideString(String s, int k, char fill) {
       int prev= 0 ;
       int curr = 0;
       int n = s.length();
        int remain = n%k;
        if(remain !=0){

        for(int   i = 0; i < k- remain; i++){
            s+=fill;
        }
        }

       String[] arr = new String[s.length()/k];
       int  i =k-1 ;
       while(i < s.length()){
            arr[i/k] = s.substring(prev, i+1);
            prev +=k;
            i+=k;
       }
       return arr;
    }
}