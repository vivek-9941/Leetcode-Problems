class Solution {
    public int findPeakElement(int[] arr) {

       int l  = 0 ;
       int n= arr.length;
       int r = n-1;
       while(l <= r){
        int mid =  (l+r)/2;
        if((mid == 0 || arr[mid-1] < arr[mid]) && (mid == n-1 || arr[mid] > arr[mid+1]) ){
            return mid;
        }
        else if(mid > 0 && arr[mid] < arr[mid-1]){
            r  =mid -1;
        }
        else{
            l = mid +1;
        }
       } 
       return -1;
    }
}