class Solution {
    void solve(List<List<Integer>> lst, int k, int n, int sum, int num, List<Integer> ds) {

        if (sum == n && ds.size() == k){
            lst.add(new ArrayList(ds));
    return;
        }
        if (sum > n || (sum < n && ds.size() >= k))
            return;
        for (int i = num; i >= 1; i--) {
            if (ds.size() < k) {
                ds.add(i);
            }
            solve(lst, k, n, sum + i, i - 1, ds);
            ds.remove(ds.size() - 1);
        }

    }

    public List<List<Integer>> combinationSum3(int k, int n) {

        List<List<Integer>> lst = new ArrayList<>();
        solve(lst, k, n, 0, 9, new ArrayList());
        return lst;
    }
}