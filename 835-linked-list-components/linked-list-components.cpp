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
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> st(nums.begin() , nums.end());
        ListNode* temp = head;
        int cnt =0;
        while(temp != nullptr){
            if(st.find(temp -> val ) != st.end()){
                while(temp != nullptr && st.find(temp -> val) != st.end())temp = temp -> next;
                cnt++;
            } 
            else{
                temp = temp -> next;
            }
        }
        return cnt;
    }
};