class Solution {
    void dijkstra(vector<int>& edges, vector<int>& hash, int n) {
        vector<int> vis(edges.size(), 0);
        int wt = 0;
        int curr = n;
        while (curr != -1 && !vis[curr]) {
            vis[curr] = 1;
            hash[curr] = wt;
            curr = edges[curr];
            wt++;
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> t1(n, INT_MAX);
        vector<int> t2(n, INT_MAX);
        dijkstra(edges, t1, node1);
        dijkstra(edges, t2, node2);
        int wt = INT_MAX;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (t1[i] != INT_MAX && t2[i] != INT_MAX) {
                int maxDist = max(t1[i], t2[i]);
                if (wt > maxDist) {
                    node = i;
                    wt = maxDist;
                }
            }
        }

        return node;
    }
};