/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(k == 0 )return head;
        if(head == null || head.next == null)return head;
        ListNode temp  = head;
        int cnt =0;
        ListNode oghead = head;
        while(temp != null){
            cnt++;
            temp = temp.next;
        }
        k = k %cnt;
        if(k == 0)return head;
        temp  = head;
       for(int i = 0 ;  i < cnt-k-1 ; i++ ){
            temp = temp.next;                
       }
       oghead = temp.next;
       temp.next = null;
       temp  = oghead;
       while(temp.next != null)
       {
        temp = temp.next;
       }
       temp.next = head;
       return oghead;
    }
}