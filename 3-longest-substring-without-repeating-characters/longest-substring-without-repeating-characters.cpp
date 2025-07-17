class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxi = 0;
        unordered_map<char, int> mpp;

        while (r < n) {
            if (mpp.find(s[r]) != mpp.end()) {
                l = max(l, mpp[s[r]] + 1);
            }
            mpp[s[r]] = r;
            maxi = max(maxi, r - l + 1);
            r++;
        }
        return maxi;
    }
};
