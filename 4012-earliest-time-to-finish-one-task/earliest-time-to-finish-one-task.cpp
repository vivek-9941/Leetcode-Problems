class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int maxi = INT_MAX;
        for(auto i : tasks)maxi = min(maxi,i[0]+i[1]);
        return maxi;
    }
};