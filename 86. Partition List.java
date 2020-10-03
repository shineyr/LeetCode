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
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode preHead = new ListNode(0, head);
        
        ListNode pre = preHead, p = head;
        
        while(p != null) {
            if (p.val < x) {
                pre = p;
                p = p.next;
                continue;
            }
            
            ListNode q = p, r = p.next;
            while (r != null && r.val >= x) {
                q = q.next;
                r = r.next;
            }
            
            // Find the one which is less than x
            if (r == null) {
                break;
            } 
            
            q.next = r.next;
            r.next = p;
            pre.next = r;
            
            
            pre = r;
        }
        
        return preHead.next;
    }
}
