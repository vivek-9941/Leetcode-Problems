class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        unordered_map<char, int> mpp;
        for (char c : s1) mpp[c]++;
        for (int i = 0; i <= m - n; i++) {
            unordered_map<char, int> k = mpp;
            bool isPermutation = true;
            for (int j = i; j < i + n; j++) {
                if (k.find(s2[j]) == k.end()) {
                    isPermutation = false;
                    break;
                }
                k[s2[j]]--;
                if (k[s2[j]] == 0) k.erase(s2[j]);
            }

            if (isPermutation && k.empty()) return true;
        }

        return false;
    }
};
