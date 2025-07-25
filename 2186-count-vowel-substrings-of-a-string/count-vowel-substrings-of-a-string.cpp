class Solution {
public:
    int countVowelSubstrings(string word) {
        int cnt = 0;
        int start = 0;
        // for (int j = 0; j < word.size(); j++) {
        //     if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
        //         word[j] == 'o' || word[j] == 'u')
        //         break;
        //     start++;
        // }
        for (int i = start; i < word.size(); i++) {
        
            unordered_map<char, int> mpp;
            for (int j = i; j < word.size(); j++) {
            
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                    word[j] == 'o' || word[j] == 'u')
                    mpp[word[j]]++;
                else break;
                if (mpp.size() == 5)
                    cnt++;
            }
        }
        return cnt;
    }
};