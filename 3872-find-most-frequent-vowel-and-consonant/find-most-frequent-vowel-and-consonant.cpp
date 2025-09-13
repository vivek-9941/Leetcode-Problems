class Solution {
    bool isvowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u')return true;
        return false;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mp1,mp2;
        for(int i =0 ; i  < s.size(); i++){
            if(isvowel(s[i]))mp1[s[i]]++;
            else mp2[s[i]]++;
        }
        int maxivowel  =0;
        for(auto it : mp1){
            maxivowel = max(maxivowel, it.second);
        }
         int maxicons  =0;
        for(auto it : mp2){
            maxicons = max(maxicons, it.second);
        }
        return maxicons+maxivowel;
        

    }
};