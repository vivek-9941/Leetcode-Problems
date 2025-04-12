class Solution {
    void dfs(int node, int[] vis, ArrayList<ArrayList<Integer>> adj, ArrayList<ArrayList<Integer>> ogadj, int[] counter) {
        vis[node] = 1;
        for (int x : adj.get(node)) {
            if (vis[x] == 0) {
                if (ogadj.get(node).contains(x)) {
                    counter[0]++; // This means the edge was originally from node -> x, so needs reversing
                }
                dfs(x, vis, adj, ogadj, counter);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        // Adjacency list (undirected for traversal)
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        // Original directed graph
        ArrayList<ArrayList<Integer>> ogadj = new ArrayList<>();
        for (int i = 0; i < n; i++) ogadj.add(new ArrayList<>());

        // Build both graphs
        for (int i = 0; i < connections.length; i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            adj.get(u).add(v);
            adj.get(v).add(u);        // undirected edge for traversal

            ogadj.get(u).add(v);      // directed edge
        }

        int[] vis = new int[n];
        int[] counter = new int[1];

        dfs(0, vis, adj, ogadj, counter); // Only start DFS from node 0

        return counter[0];
    }
}
