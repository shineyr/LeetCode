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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null || m >= n) {
            return head;
        }
        
        ListNode root = new ListNode(0), preHead = root;
        root.next = head;
        
        ListNode pre = root, p = head, next = null, tail = null;
        
        int idx = 1;
        while(p != null && idx < m) {
            preHead = p;
            p = p.next;
            ++idx;
        }
        
        if (p == null || idx != m) {
            return head;
        }
        
        tail = p;
        pre = p;
        p = p.next;
        ++idx;
        
        while(p != null && idx <= n) {
            next = p.next;
            p.next = pre;
            pre = p;
            p = next;
            ++idx;
        }
        
        tail.next = next;
        preHead.next = pre;
        
        return root.next;
    }
}
