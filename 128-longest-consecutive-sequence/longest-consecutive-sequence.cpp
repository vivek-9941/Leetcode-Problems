class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int num : st) { // ensures unique numbers
            if (st.find(num - 1) == st.end()) { // start of sequence
                int curr = num;
                int currStreak = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    currStreak++;
                }

                longest = max(longest, currStreak);
            }
        }

        return longest;
    }
};
