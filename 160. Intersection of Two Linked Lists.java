/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        
        int lenA = 0, lenB = 0;
        
        ListNode pA = headA;
        while(pA != null) {
            ++lenA;
            pA = pA.next;
        }
        
        ListNode pB = headB;
        while(pB != null) {
            ++lenB;
            pB = pB.next;
        }
        
        int minLen = Math.min(lenA, lenB);
        pA = headA;
        pB = headB;
        while(lenA > minLen) {
            pA = pA.next;
            --lenA;
        }
        
        while(lenB > minLen) {
            pB = pB.next;
            --lenB;
        }
        
        while(pA != null && pB != null) {
            if (pA == pB) {
                return pA;
            }
            
            if (pA.next == pB.next) {
                return pA.next;
            } 
            
            pA = pA.next;
            pB = pB.next;
            
        }
        
        return null;
    }
}
