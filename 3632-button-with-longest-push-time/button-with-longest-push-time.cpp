class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int index = events[0][0];  // Start with the first button
        int prev = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < events.size(); i++) {
            int diff = events[i][1] - prev;
            if (diff > maxi) {
                maxi = diff;
                index = events[i][0];
            } else if (diff == maxi) {
                index = min(index, events[i][0]);  // choose smaller ID
            }
            prev = events[i][1];
        }
        return index;
    }
};
