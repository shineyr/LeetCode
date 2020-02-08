/**
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the n-th node from the end of list and return its head.
 *
 * Example:
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Note:
 *
 * Given n will always be valid.
 */
public class NO_19 {
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */

    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            this.val = x;
        }
    }

    class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            ListNode pre = head, p = head;

            while (n >= 0 && p != null) {
                p = p.next;
                --n;
            }

            if (p == null && n == 0) {
                return head.next;
            }

            while (p != null) {
                p = p.next;
                pre = pre.next;
            }

            if (pre == null || pre.next == null) {
                return head;
            }

            pre.next = pre.next.next;
            return head;
        }
    }
}
