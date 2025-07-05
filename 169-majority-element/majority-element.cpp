class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int countmaj = 1;
        int countother = 0;
        int el = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            if(countmaj == 0){
                countmaj = 1;
                // countother =0;
                el = nums[i];
            }
           else  if(nums[i] == el)countmaj++;
            else{
                countmaj--;
            }
        }
        return el;
    }
};