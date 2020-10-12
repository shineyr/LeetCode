/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        
        // now delete node.next
        node.next = node.next.next;
    }
    
    public void deleteNode1(ListNode node) {
        if (node == null) {
            return;
        }
        
        ListNode pre = node, next = node.next;
        
        while(next != null) {
            int tmp = node.val;
            node.val = next.val;
            next.val = tmp;
            
            pre = node;
            node = next;
            next = node.next;
        }
        
        pre.next = null;
    }
}
