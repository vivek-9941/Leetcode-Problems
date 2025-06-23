class Solution {
    boolean dfs(int  node, int [][] graph, int [] vis,int []color){
        vis[node] = 1;
        for(int X : graph[node]){
            if(vis[X] == 0){
                color[X] =  1 ^ color[node];
                if(!dfs(X , graph , vis, color))return false;
            }
            else{
                if(color[X] == color[node])return false;
            }
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] vis = new int[n];
        int [] color = new int[n];
        color[0] = 1;
        for (int i = 0; i < n; i++) {
          if(vis[i] == 0)
          {
            if(!dfs(i , graph  ,vis ,color))return false;
          }
        }
        return true;
    }
}