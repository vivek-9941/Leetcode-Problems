class Solution {
    bool produce(vector<int> arr, int days , int m , int k){
        int n = arr.size();
        int cnt= 0;
        int boq =0;
        for(int i =0 ; i < n ;i++){
            if(arr[i] <= days){
                cnt++;
            }
            else{
                boq += cnt/k;
                cnt= 0;
            }

        }
        boq += cnt/k;
        return boq >=m;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {
        int mini = *min_element(arr.begin(), arr.end());
        int maxi = *max_element(arr.begin(),arr.end());
        int l  = mini , h  =maxi;
        long long val  =  m* 1LL * k*1LL;
        if(val> arr.size())return -1;
        int ans =0;
        while(l <= h){
            int mid= (l+h)/2;
            if(produce(arr,mid, m,k )){
                h = mid -1;
            }
            else{   
                l = mid +1;
            }
        }
        return l;
    }
};