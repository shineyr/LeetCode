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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode newHead = null, p = head;
        
        while(p != null) {
            ListNode r = p.next;
            
            if (newHead == null) {
                newHead = p;
                newHead.next = null;
            } else if (p.val < newHead.val) {
                p.next = newHead;
                newHead = p;
            } else {
                ListNode pre = newHead, q = newHead.next;
                while(q != null && q.val < p.val) {
                    pre = q;
                    q = q.next;
                }
                
                p.next = q;
                pre.next = p;
            }
            
            p = r;
        }
        
        return newHead;
    }
    
    public ListNode insertionSortList1(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode nextHead = insertionSortList(head.next);
        
        if (head.val < nextHead.val) {
            head.next = nextHead;
            return head;
        }
        
        ListNode pre = nextHead, p = nextHead.next;
        
        while(p != null && p.val < head.val) {
            pre = p;
            p = p.next;
        }
        
        head.next = p;
        pre.next = head;
        
        return nextHead;
    }
}
