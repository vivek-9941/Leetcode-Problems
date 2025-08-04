class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int l  =0 ;          
        int maxi  = 0;              
        for(int i  =0 ; i < fruits.size(); i++){
            mpp[fruits[i]]++;
            if(mpp.size()  > 2 ){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0)mpp.erase(fruits[l]);
                l++;
            }
            maxi = max(maxi , i-l +1 );
        }
        return maxi;
    }
};