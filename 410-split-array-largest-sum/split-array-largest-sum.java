class Solution {
    int getpartition(int[] nums, int k , int target ){
        int sum =0;
        int cnt= 1;
        for(int i =0; i < nums.length; i++){
            if(sum + nums[i] <= target){
                sum += nums[i];

            }
            else{
                sum =nums[i];
                cnt++;
            }
        }
        return cnt;
    }
    public int splitArray(int[] nums, int k) {
        int l = Arrays.stream(nums).max().getAsInt();
        int h = Arrays.stream(nums).sum();
        int ans  = -1;
        while(l <= h){
            int mid = (l+h)/2;
            if(getpartition(nums, k, mid) <= k){
                ans = mid;
                h= mid -1;
            }
            else{
                l = mid +1;
            }
        }
        return ans;

    }
}