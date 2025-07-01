class Solution {
public:
    int possibleStringCount(string word) {
        int cnt =0;
        if(word.size()==1)return 1;
        for(int i = 1;  i < word.size();i++){
            if(word[i] == word[i-1])cnt++;
        }
        return cnt+1;
    }
};