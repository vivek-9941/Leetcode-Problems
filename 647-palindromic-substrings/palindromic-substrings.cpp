class Solution {
    bool palan(string s){
        string k= s;
        reverse(k.begin(),k.end());
        return k == s;
    }
   
public:
    int countSubstrings(string s) {
        int cnt =0;
        for(int  i = 0 ; i  <s.size(); i++){
            for(int j  = i ;  j < s.size(); j++){
                string k(s.begin()+i, s.begin()+j+1);
                if(palan(k))cnt++;
            }
        } 
        return cnt;
    }
};