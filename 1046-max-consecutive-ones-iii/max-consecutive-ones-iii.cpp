class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, maxlen = 0, len = 0, zero = 0;
        int n = nums.size();

        while (r < n) {
            if (nums[r] == 0)
                zero++;
           
                while(zero > k &&  l < n){
                    if(nums[l] == 0)zero--;
                    l++;
                }
            
            len = r-l+1;
            maxlen= max(maxlen , len);
r++;
        }
        return maxlen;
    }
};