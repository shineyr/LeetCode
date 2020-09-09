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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode root = new ListNode(0, head);
        ListNode cur = head, prev = root;
        
        while(cur != null) {
            // Grab current tail for next reverse
            ListNode tail = cur;
            int idx = 0;
            
            while(cur != null && idx < k) {
                cur = cur.next;
                ++idx;
            }
            
            if (idx != k) {
                // less than k nodes
                prev.next = tail;
            } else {
                // reverse these k nodes
                prev.next = reverse(tail, k);
                
                prev = tail;
            }
        }
        
        return root.next;
    }
    
    private ListNode reverse(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode prev = null, cur = head, next = null;
        while(cur != null && k-- > 0) {
            next = cur.next;
            cur.next = prev;
            
            prev = cur;
            cur = next;
        }
        
        head = prev;
        
        return head;
    }
}
