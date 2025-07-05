class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0;
        int n = arr.size();
        int purchase= 0;
        int cost = arr[0];
        for (int i = 0; i < n; i++) {
            cost = arr[i] - arr[purchase];
             profit = max(profit, cost);
             if(cost < 0){
                purchase = i;

             }
        }
        return profit;
    }
};