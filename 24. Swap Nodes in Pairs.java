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
    // Solution 2
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode nextHead = swapPairs(head.next.next);
        
        ListNode p = head, q = head.next;
        p.next = nextHead;
        q.next = p;
        
        head = q;
        
        return head;
    }
    
    // Solution 1
    public ListNode swapPairs1(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode p = head, q = p.next, r = q.next;
        
        head = q;
        q.next = p;
        p.next = r;
        
        // Record the previous node before next swap combination nodes
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
