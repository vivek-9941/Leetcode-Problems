
class Solution {
    void dfs(vector<vector<int>>& adj ,vector<int> &vis,int node ){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0; i <  n ; i++) {
            for(int j =0 ; j <m  ; j++){
                if(isConnected[i][j] && i!= j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }  

        vector<int> vis(adj.size(),0);
        int cnt =0;
        for(int i= 0 ; i< adj.size() ;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cnt++;
            }

        }
        return cnt;


    }
};