class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
        mpp[nums[i]]++;
        }
        int sum = 0;
        int maxi =0;
        int largestnegative = INT_MIN;
        int cntnegative  =0;
        for(auto it : mpp){
            sum = it.first;
            if(sum <= 0){
                cntnegative+= it.second;
                largestnegative = max ( largestnegative , it.first);
            }
            else maxi += sum;
        }
        if(cntnegative == nums.size())return largestnegative;
        return maxi;
    }
};