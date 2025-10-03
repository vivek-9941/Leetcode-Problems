/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;  // fixed typo
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void solve(ListNode* head){
        ListNode* prev = head;
        while (prev->next && prev->next->next) {
            ListNode* first  = prev->next;
            ListNode* second = first->next;

            // perform swap of the pair (prev -> second -> first -> next)
            prev->next    = second;
            first->next   = second->next;
            second->next  = first;

            // move prev to the node before the next pair
            prev = first;
        }
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        // create a dummy so solve() can uniformly handle head swaps
        ListNode dummy(0);
        dummy.next = head;

        solve(&dummy);
        return dummy.next;
    }
};
