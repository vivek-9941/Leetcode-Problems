class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int currsum = 0;
        int maxi = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[nums[r]]++;
            currsum += nums[r];

            while (l < n && mpp[nums[r]] > 1) {

                mpp[nums[l]]--;
                currsum -= nums[l];
                l++;
            }

            maxi = max(maxi, currsum);
            r++;
        }
        return maxi;
    }
};