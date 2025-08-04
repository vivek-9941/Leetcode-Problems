class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int maxi = sum;
        int n = arr.size();

        for (int i = 1; i <= k; i++) {
            sum -= arr[k - i];           // Remove from front
            sum += arr[n - i];           // Add from back
            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
