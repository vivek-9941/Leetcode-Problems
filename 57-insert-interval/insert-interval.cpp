class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
         vector<vector<int>> vrr,arr;
         bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (!inserted && newinterval[0] < intervals[i][0]) {
                vrr.push_back(newinterval);
                inserted = true;
            }
            vrr.push_back(intervals[i]);
        }
        if (!inserted) {
            vrr.push_back(newinterval);
        }

        for(int i  = 0; i  < vrr.size(); i++){
            if(arr.empty() || arr.back()[1] < vrr[i][0])arr.push_back(vrr[i]);
            else{
                arr.back()[1] = max(arr.back()[1] , vrr[i][1]);
            
            }
        }
        return arr;
    }
};