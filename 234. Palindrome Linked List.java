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
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Now slow is in mid of list
        ListNode rightHead = slow.next, rNext = rightHead.next;
        
        slow.next = null;
        rightHead.next = null;
        
        while(rNext != null) {
            ListNode r = rNext.next;
            
            rNext.next = rightHead;
            rightHead = rNext;
            
            rNext = r;
        }
        
        ListNode pLeft = head, pRight = rightHead;
        while(pLeft != null && pRight != null) {
            if (pRight.val != pLeft.val) {
                return false;
            }
            
            pLeft = pLeft.next;
            pRight = pRight.next;
        }
        
        return true;
        
    }
    
    public boolean isPalindrome1(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Now slow is in mid of list
        Stack<Integer> stack = new Stack();
        fast = slow.next;
        while(fast != null) {
            stack.push(fast.val);
            fast = fast.next;
        }
        
        slow = head;
        while(!stack.isEmpty()) {
            if (slow == null || slow.val != stack.pop()) {
                return false;
            }
            
            slow = slow.next;
        }
        
        return true;
    }
}
