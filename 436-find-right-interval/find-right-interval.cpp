class Solution {
    int solve(int endj,vector<pair<int,int>>& arr ){
        int l =0 ; int  r = arr.size()-1;
        int ind = -1;
        while(l <= r){
            int mid =  (l+r)/2;
            if(arr[mid].first >= endj){
                ind = mid;
                r =  mid -1;
            }
            else l = mid +1;
        }
        return (ind == -1 ? -1 : arr[ind].second);
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        vector<pair<int,int> > interval;
        for(int i = 0; i  < n ; i++){
            interval.push_back({arr[i][0] , i});
        }
        sort(interval.begin() ,interval.end());
        
        for(int i = 0; i < n ; i++){
           ans[i] = solve(arr[i][1] ,  interval);    
        }  
        return ans;
    }
};