/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node temp  = head;
        while(temp != null){//insrt inbetween the nodes
            Node copy = new Node(temp.val);
            copy.next =temp.next;
            temp.next = copy;
            temp = temp.next.next;
        }
        //connect randonm opinter
        temp = head;
        while(temp != null){
            Node copy = temp.next;
           if(temp.random != null)copy.random = temp.random.next;
           else copy.random = null;
            temp = temp.next.next;
        }

        //connecting the next pointers
        Node dummy  = new Node(-1);
        Node res = dummy;
        temp  = head;
        while(temp!= null){
                res.next = temp.next;
                temp.next = temp.next.next;
                res = res.next;
                temp = temp.next;

        }
        return dummy.next;
    }
}