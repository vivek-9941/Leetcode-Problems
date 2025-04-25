class Solution {
    public int singleNumber(int[] nums) {
        int zorr  =0;
        for(int  i =0 ; i < nums.length; i++){
            zorr = nums[i]^zorr;
        }
        return zorr;
    }
}