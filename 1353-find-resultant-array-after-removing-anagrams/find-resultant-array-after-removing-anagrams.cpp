class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int  i = 1 ;
        while(i <  words.size()){
            string prev = words[i-1];
            string cur  = words[i];
            sort(cur.begin() , cur.end());
            sort(prev.begin(), prev.end());
            if(prev == cur){
                words.erase(words.begin() + i);
            }
            else  i++;
        }
        return words;
    }
};