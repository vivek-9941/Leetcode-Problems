class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();

        vector<long long> arr(n, 0);
        for (int i = 0; i < n; i++) {
            arr[edges[i]] += i;
        }
        long long  maxi = -1;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
                ind = i;
            }
        }
        return ind;
    }
};