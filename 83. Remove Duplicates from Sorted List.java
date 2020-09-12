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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode p = head, q = head.next;
        
        while(q != null) {
            if (q.val != p.val) {
                p.next = q;
                p = q;
            }
            q = q.next;
        }
        
        p.next = q;
        
        return head;
    }
}
