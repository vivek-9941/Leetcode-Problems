class Solution {
public:
    int trap(vector<int>& arr) {
        int lmax = 0, rmax = 0, l = 0, total = 0;
        int n = arr.size();
        int r = n - 1;
        int prefix[n];
        int suffix[n] ;
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];

        for(int i  = 1 ; i<n ; i++ ){
            prefix[i] = max(prefix[i-1] , arr[i]);

        }
         for(int i  = n-2; i >= 0; i-- ){
            suffix[i] = max(suffix[i+1] , arr[i]);
            
        }
        for(int i  =0  ;i  < n ; i++){
            total += min(prefix[i] , suffix[i])  - arr[i];

        }
        // while (l < r) {
        //     if (arr[l] <= arr[r]) {
        //         if (lmax > arr[l]) {
        //             total += lmax - arr[l];
        //         } else {
        //             lmax = arr[l];
        //         }
        //         l++;
        //     } else {
        //         if (rmax > arr[r]) {
        //             total += rmax - arr[r];
        //         } else {
        //             rmax = arr[r];
        //         }
        //         r--;
        //     }
        // }
        return total;
    }
};