#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        multimap<int, string> mpp; // allows multiple words of same length
        int prev = 0;
        for(int i = 0;  i  <text.size(); i++){
            text[i] = tolower(text[i]);
        }
        // extract words
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                string txt = text.substr(prev, i - prev);
                mpp.insert({txt.size(), txt});
                prev = i + 1; 
            }
        }
        // capture last word
        string last = text.substr(prev);
        mpp.insert({last.size(), last});
        
        // build result
        string ans = "";
        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            ans += it->second + " ";
        }

        // remove trailing space
        if (!ans.empty()) ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};

