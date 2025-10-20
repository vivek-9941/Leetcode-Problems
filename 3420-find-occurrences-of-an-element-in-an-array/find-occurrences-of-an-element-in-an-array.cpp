class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
         vector<int>  mpp;
        for(int i =0; i < nums.size(); i++){
            if(nums[i] == x)
            mpp.push_back(i);
        }
        vector<int> arr(queries.size());

        for(int i  =0 ; i < queries.size(); i++){
            if(mpp.size() >= queries[i]){
                arr[i] = mpp[queries[i]-1];
            }
            else{
                arr[i] = -1;
            }
        }
        return arr;
    }
};