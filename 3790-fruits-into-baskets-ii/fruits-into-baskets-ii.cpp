class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& arr) {
        int n = arr.size();
        vector<bool > used(n,false);
        int cnt =0;
       
        for(int i  =0  ; i < fruits.size(); i++){
            bool found =0;
            for(int  j =0 ;  j < n ; j++){
                if( arr[j] >= fruits[i] && !used[j]){
                    found = 1;
                    used[j] = 1;
                    break;
                }
            }
            if(!found)cnt++;
        }
        return cnt;
    }
};