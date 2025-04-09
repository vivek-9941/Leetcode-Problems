class Solution {
    public int minOperations(int[] nums, int k) {
        Map<Integer, Integer> mpp = new HashMap<>();
        for(int i  =  0 ; i<  nums.length; i++){
            mpp.put(nums[i] , mpp.getOrDefault(nums[i] , 0 )+1);

        }
        Set<Integer> st = mpp.keySet();
        int cnt= 0;
        int found = 0;
 
        for(int x: st){
            if(x < k)found = 1;
            if(x>k)cnt++;
        }
    return found == 1 ? -1 : cnt;
    }
}