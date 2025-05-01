class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> mpp =  new HashMap();
        int count  = 0;

        for(int  i = 0 ; i  < nums.length; i++){
            count += mpp.getOrDefault(nums[i] , 0);
            mpp.put(nums[i] , mpp.getOrDefault(nums[i], 0)+1);

        }
        return count;
    }
}