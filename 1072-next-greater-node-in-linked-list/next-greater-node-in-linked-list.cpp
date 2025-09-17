/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void nge(vector<int>& arr ,vector<int>& ans ){
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0 ; i--){
            while(!st.empty() && st.top() <= arr[i])st.pop();
            if(st.empty())ans[i] =  0;
            else ans[i] = st.top();
            st.push(arr[i]);
        }
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode* temp  = head;
        while(temp != nullptr){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        vector<int> ans(arr.size());
        nge(arr, ans);
        return ans;
    }
};