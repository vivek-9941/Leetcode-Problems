class Solution {
    private void findall(int index , int[] arr, int target, List<List<Integer>> ans,  List<Integer> ds){
        if(target == 0){
            ans.add(new ArrayList(ds));

            return ;
        }
        for(int i  = index ; i < arr.length;  i++){
               if(i > index  && arr[i] == arr[i-1]){
                continue;
               }
               if(arr[i] > target )break;
               ds.add(arr[i]);
                findall(i+1, arr, target - arr[i],ans,ds ) ;
                ds.remove(ds.size()-1);

                
        }
    }
    public List<List<Integer>> combinationSum2(int[] arr, int target) {
        List<List<Integer>> ans =  new ArrayList<>();

      Arrays.sort(arr);
      findall(0, arr, target,ans,  new ArrayList<>() ) ;
return ans;
    }
}