class Solution {
    void solve(int[] nums , int index , List<List<Integer>> lst , List<Integer> ds){
        lst.add(new ArrayList(ds));
        for(int i = index; i < nums.length; i++){
            if( i != index && nums[ i] == nums[i-1])continue;
            ds.add(nums[i]);
            solve(nums ,i+ 1 , lst , ds);
            ds.remove(ds.size() -1);

        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> lst = new ArrayList<>();
        Arrays.sort(nums);
        solve(nums, 0 , lst , new ArrayList<>()); 
        return lst;
    }
}