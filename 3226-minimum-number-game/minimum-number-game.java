class Solution {
    public int[] numberGame(int[] nums) {
        PriorityQueue<Integer> st =new PriorityQueue<>();
        for(int  i = 0 ;  i< nums.length; i++){
            st.add(nums[i]);
       }
       int [] arr  =new int[nums.length];
       int i =  0;
      while(!st.isEmpty()){
        int first = st.poll();
        int second = st.poll();
        arr[i]  = second;
        i++;
        arr[i] =  first;
        i++;

      }
return arr;
    }
}