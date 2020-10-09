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
        if (head == null || head.next == null || k <= 0) {
            return head;
        }
        
        // Step 1 count the length of this list
        int len = 0;
        ListNode p = head;
        while(p != null) {
            p = p.next;
            ++len;
        }
        
        k %= len;
        
        // No need to rotate
        if (k == 0) {
            return head;
        }
        
        // Find the right k pre node
        p = head;
        int i = 1;
        
        while (p != null && i < len - k) {
            ++i;
            p = p.next;
        }
        
        
        // Tag the current end and head
        ListNode newEnd = p, newHead = p.next;
        
        // Find the rotate node
        while(p.next != null) {
            p = p.next;
        }
        
        // Rotate
        p.next = head;
        newEnd.next = null;
        
        return newHead;
    }
}
