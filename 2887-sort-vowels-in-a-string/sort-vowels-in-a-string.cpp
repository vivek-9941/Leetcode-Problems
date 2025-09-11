class Solution {
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')return true;
        return false;
    }
public:
    string sortVowels(string s) {
        vector<char> strings;
        vector<char> vowels;
        for(int i = 0 ; i < s.size() ; i++){
            if(isvowel(tolower(s[i]))){
            strings.push_back('.');
            vowels.push_back(s[i]);
            }
            else{
                strings.push_back(s[i]);
            }
        }
        sort(vowels.begin(), vowels.end());
        int  j = 0;
        for(int i =0 ; i < s.size() ; i++)
        {
            if(strings[i] == '.'){
                strings[i] = vowels[j++];
            }
        }
        string ans(strings.begin(), strings.end());
        return ans;
    }
};