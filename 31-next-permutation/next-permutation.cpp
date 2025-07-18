class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

       int r =  n-1;
       int index=  -1;
        for(int i = n -2 ; i>=0; i--){
            if(nums[i]  < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){

        reverse(nums.begin() , nums.end());
        }
        else{
            for(int i = n-1 ; i >=0 ; i--){
                if(nums[index] < nums[i]){
                    swap(nums[index] , nums[i]);
                    break;
                }

            }
            reverse(nums.begin() + index+1  ,nums.end());
        }

    }
};