class Solution {
    public int smallestNumber(int n) {
       int req = 2;
       while(true){
        if(req > n ){
            return req-1;
        }
        else 
         req = req << 1;
       } 
    }
}