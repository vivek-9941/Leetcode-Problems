class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() ,intervals.end(), [](auto &a , auto &b){
            return a[1] < b[1];
        });
        int cnt =0;
        int prevend= intervals[0][1];
        int n = intervals.size();
        for(int i  =1; i < n;i++){
            if(intervals[i][0] < prevend){
                cnt++;
            }
            else{

                prevend = intervals[i][1];
            }
            }
        
        return cnt;
    }
};