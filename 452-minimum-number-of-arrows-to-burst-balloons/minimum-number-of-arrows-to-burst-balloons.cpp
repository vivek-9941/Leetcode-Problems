class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort by end time to apply greedy logic
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        int end = points[0][1];  // The position of the last arrow

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {
                // New arrow needed
                arrows++;
                end = points[i][1];
            }
            // else, the current balloon is already covered
        }

        return arrows;
    }
};
