/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        
        ListNode slow = head, fast = head;
        
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                fast = head;
                break;
            }
        }
        
        while(fast != null && fast.next != null) {
            if (fast == slow) {
                return slow;
            }
            
            fast = fast.next;
            slow = slow.next;
        }
        
        return null;
    }
}
