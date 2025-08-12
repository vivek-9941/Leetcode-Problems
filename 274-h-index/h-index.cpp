class Solution {
public:
    int hIndex(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int h = n - i; // possible h-index at this point
            if(arr[i] >= h) {
                maxi = h; // h-index found
                break;    // since sorted, no need to check further
            }
        }
        return maxi;
    }
};
