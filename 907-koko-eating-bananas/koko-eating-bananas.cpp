class Solution {
    long long calculatehrs(const vector<int>& piles, int perhr) {
        long long hrs = 0;
        for (int pile : piles) {
            hrs += (pile + perhr - 1LL) / perhr;  // safe ceiling division
        }
        return hrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1;
        int h = *max_element(piles.begin(), piles.end());
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            long long takenhrs = calculatehrs(piles, mid);  // long long here

            if (takenhrs <= hrs) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
