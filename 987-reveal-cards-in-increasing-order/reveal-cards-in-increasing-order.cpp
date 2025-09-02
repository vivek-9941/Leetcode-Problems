class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin() ,deck.end());
        for(int i =0 ; i < deck.size(); i++){
            q.push(i);

        }
        int i =0;
        vector<int> ans(deck.size());
        while(!q.empty()){
            ans[q.front()] =  deck[i++];q.pop();
            if(q.front()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;

    }
};