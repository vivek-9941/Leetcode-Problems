class Solution {

    private void findall(int index, int[] candidates, int target, List<List<Integer>> ans, List<Integer> ds) {
        if (index == candidates.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(ds));

            }
            return;
        }

        if (target >= candidates[index]) {
            ds.add(candidates[index]);
            findall(index, candidates, target - candidates[index], ans, ds);
            ds.remove(ds.size() - 1);
        }
        findall(index + 1, candidates, target, ans, ds);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findall(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
}