class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> st;
        unordered_map <int,int> mpp;
        for(int i = 0; i < matches.size();i++){
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
            mpp[matches[i][1]]++;
        }
        vector<int> first , second ;
        
        for(auto it: st){
            if(mpp.find(it) == mpp.end()){
                first.push_back(it);
            }
            else if (mpp[it] == 1){
                second.push_back(it);
            }
        }
        vector<vector<int> > arr;
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        arr.push_back(first);
        arr.push_back(second);
        return arr;
    }
};