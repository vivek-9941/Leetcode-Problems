class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] % 2;
            if (mpp.find(sum - k) != mpp.end()) {
                cnt+= mpp[sum-k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};