/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> arr;
        if (!root)
            return arr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            vector<int> k;

            for (int i = 0; i < n; i++) {
                vector<Node*> child = q.front() -> children;
                for(int i = 0 ;  i < child.size();i++){
                    q.push(child[i]);
                }
                k.push_back(q.front() -> val);
                q.pop();

            }
            arr.push_back(k);
        }
        return arr;
    }
};