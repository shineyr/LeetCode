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
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode p = head, newHead = null;
        
        while (p != null) {
            ListNode r = p.next;
            
            p.next = newHead;
            
            newHead = p;
            
            p = r;
        }
        
        return newHead;
    }
        
    public ListNode reverseList1(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode nextHead = reverseList(head.next);
        
        ListNode p = nextHead;
        while(p.next != null) {
            p = p.next;
        }
        
        p.next = head;
        head.next = null;
        
        return nextHead;
    }
}
