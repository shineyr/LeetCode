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
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return head;
        }
        
        ListNode nextHead = removeElements(head.next, val);
        
        if (head.val == val) {
            return nextHead;
        } 
        
        head.next = nextHead;
        
        return head;
    }
    
    public ListNode removeElements1(ListNode head, int val) {
        if (head == null) {
            return head;
        }
        
        while(head != null && head.val == val) {
            head = head.next;
        }
        
        if (head == null) {
            return head;
        }
        
        ListNode pre = head, p = head.next;
        while(p != null) {
            if (p.val == val) {
                pre.next = p.next;
                p = p.next;
            } else {
                pre = p;
                p = p.next;
            }
        }
        
        return head;
    }
    
    
}
