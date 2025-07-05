class Solution {
    void swap(int arr[], int l , int r){
        int temp = arr[l];
        arr[l] =  arr[r];
        arr[r] = temp;
    }
    public void sortColors(int[] arr) {
        int n  = arr.length;
        int l =0;
        int r = n-1;
        for(int i  = n-1 ; i>=0; i--)
        {
            while( l < n && arr[l] ==0)l++;
            if(l >= i)break;
            if(l>= n)break;
            if(arr[i] == 0){
                swap(arr,i,l);
            }
            
        }
        for(int i  =0; i < n;i++){
            while( r >=0 &&  arr[r] == 2)r--;
            if(r <= i )break;
            if(r<= 0)break;
            if(arr[i] == 2){
                swap(arr,i,r);
            }

        }


    }
}