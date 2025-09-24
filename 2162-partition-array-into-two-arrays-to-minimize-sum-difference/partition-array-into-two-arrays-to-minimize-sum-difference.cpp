class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        long long totalsum = accumulate(nums.begin(), nums.end(), 0LL);

        // Split into 2 halves
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Function to generate all subset sums with their counts
        auto gen = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<long long>> res(m+1);
            for (int mask = 0; mask < (1<<m); mask++) {
                long long sum = 0;
                int cnt = 0;
                for (int i = 0; i < m; i++) {
                    if (mask & (1<<i)) {
                        sum += arr[i];
                        cnt++;
                    }
                }
                res[cnt].push_back(sum);
            }
            for (int i = 0; i <= m; i++) sort(res[i].begin(), res[i].end());
            return res;
        };

        auto leftSums = gen(left);
        auto rightSums = gen(right);

        long long ans = LLONG_MAX;

        // Try all splits: pick k from left, n-k from right
        for (int k = 0; k <= n; k++) {
            auto& A = leftSums[k];
            auto& B = rightSums[n-k];

            for (long long x : A) {
                long long target = totalsum/2 - x;
                auto it = lower_bound(B.begin(), B.end(), target);

                if (it != B.end()) {
                    long long s1 = x + *it;
                    long long s2 = totalsum - s1;
                    ans = min(ans, llabs(s2 - s1));
                }
                if (it != B.begin()) {
                    --it;
                    long long s1 = x + *it;
                    long long s2 = totalsum - s1;
                    ans = min(ans, llabs(s2 - s1));
                }
            }
        }

        return (int)ans;
    }
};
