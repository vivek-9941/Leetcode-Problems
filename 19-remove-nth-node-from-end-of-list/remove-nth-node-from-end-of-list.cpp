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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;

  
        while (n-- && fast) {
            fast = fast->next;
        }

       
        if (!fast) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* prev = nullptr;


        while (fast) {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
     
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
