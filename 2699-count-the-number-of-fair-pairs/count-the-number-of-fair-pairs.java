class Solution {
    int findlargset(int[] nums, int i, int upper) {
        int l = i + 1;
        int r = nums.length - 1;
        int result = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] + nums[i] <= upper) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }

    int findsmallest(int[] nums, int i, int lower) {
        int l = i + 1;
        int r = nums.length - 1;
        int result = nums.length;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] + nums[i] >= lower) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    public long countFairPairs(int[] nums, int lower, int upper) {
        long pairs = 0;
        Arrays.sort(nums);
        int n = nums.length;
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {

            int l = findsmallest(nums, i, lower);
            int r = findlargset(nums, i, upper);
            if (l <= r) {

                pairs += r - l + 1;
            }
        }
        return pairs;
    }
}