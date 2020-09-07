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
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode p = head, q = p.next, r = q.next;
        
        head = q;
        q.next = p;
        p.next = r;
        
        ListNode pre = p;
        
        while (r != null && r.next != null) {
            p = r;
            q = p.next;
            r = q.next;
            
            pre.next = q;
            q.next = p;
            p.next = r;
            
            pre = p;
        }
        
        return head;
    }
}
