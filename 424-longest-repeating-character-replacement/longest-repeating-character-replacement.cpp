class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int j =0, maxi = 0, res  =0;
        for(int i = 0 ; i < s.size();i++){
            mpp[s[i]]++;
            maxi  = max(maxi , mpp[s[i]]);
            while((i-j  +1 )  - maxi > k){
                mpp[s[j]]--;
                j++;
            } 
            res = max(res , i - j +1);

        }
        return res;
    }
};