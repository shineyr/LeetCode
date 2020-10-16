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
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Now slow is in mid of list
        ListNode rest = slow.next;
        slow.next = null;
        
        // Reverse right half
        ListNode rightHead = rest, p = rest.next;
        rightHead.next = null;
        
        while (p != null) {
            ListNode r = p.next;
            
            p.next = rightHead;
            rightHead = p;
            
            p = r;
        }

        // Merge two lists
        ListNode pLeft = head, pRight = rightHead;
        while(pLeft != null && pRight != null) {
            ListNode rLeft = pLeft.next, rRight = pRight.next;
            
            pRight.next = pLeft.next;
            pLeft.next = pRight;
            
            pLeft = rLeft;
            pRight = rRight;
        }
        
    }
    
    public void reorderList1(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Now slow is in mid of list
        ListNode rest = slow.next;
        slow.next = null;
        
        Stack<ListNode> stack = new Stack();
        while(rest != null) {
            stack.push(rest);
            rest = rest.next;
        }
        
        ListNode p = head;
        while(stack.size() > 0) {
            stack.peek().next = p.next;
            p.next = stack.pop();
            p = p.next.next;
        }
    }
}
