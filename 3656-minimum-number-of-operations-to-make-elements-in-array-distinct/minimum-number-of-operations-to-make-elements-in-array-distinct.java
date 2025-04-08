class Solution {
    public int minimumOperations(int[] nums) {
        int index= -1;
        Map<Integer,Integer> mpp = new HashMap<>(); 
        for(int i =nums.length-1 ; i >=0 ; i--){
            mpp.put(nums[i] , mpp.getOrDefault(nums[i] , 0) +1);
            if(mpp.get(nums[i]) > 1 ){
                index = i;
                break;}
        
        }
        int req =( index +1)/3;
        if((index+1)%3 !=0)req++;
        return req;
    }
}