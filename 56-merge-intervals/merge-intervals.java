class Solution {
    public int[][] merge(int[][] intervals) {
        List<List<Integer>> lst  = new ArrayList<>();
        int n = intervals.length;
        Arrays.sort(intervals , new Comparator<int[]>(){
                public int compare(int[] a,int []b ){
                    return a[0] - b[0];
                }
        });
        for(int i =0 ; i < n;i++){
            if(lst.isEmpty() || lst.get(lst.size()-1).get(1) < intervals[i][0]){
                lst.add(Arrays.asList(intervals[i][0] , intervals[i][1]));

            }
            else{
                lst.get(lst.size()-1).set(1, Math.max(intervals[i][1], lst.get(lst.size()-1).get(1))); 
            }
        }
        n = lst.size();
        int [][] ans = new int[n][2];

        for(int i  =0 ; i < n ;i++){
            ans[i][0] = lst.get(i).get(0);
            ans[i][1] =lst.get(i).get(1);
        }
        return ans;
    }

}