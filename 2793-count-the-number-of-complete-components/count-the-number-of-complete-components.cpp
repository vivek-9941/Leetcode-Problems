class Solution {
    void dfs(vector<vector<int>>& adj , int node ,int& v , int &e,vector<int> &vis){
        vis[node] = 1;
        v++;
        for(auto it : adj[node]){
            e++;
            if(!vis[it]){
                dfs(adj, it, v,e,vis);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int cnt =0 ;
        for(int i = 0 ;  i  < n ; i++){
            if(!vis[i]){
                int v = 0,  e = 0;
                dfs(adj,i,v,e ,vis);
                if((v*(v-1))/2 == e/2)cnt++;
            }
        }
        return cnt;
    }
};