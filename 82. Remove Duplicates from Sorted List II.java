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
        
        ListNode preHead = new ListNode(0, head);
        
        ListNode pre = preHead, p = head;
        
        while (p != null) {
            if (p.next == null) {
                break;
            } else if (p.next != null && p.next.val != p.val) {
                pre = p;
                p = p.next;
            } else {
                int curVal = p.val;
                
                while(p != null && p.val == curVal) {
                    p = p.next;
                }
                
                pre.next = p;
            }
        }
        
        return preHead.next;
    }
}
