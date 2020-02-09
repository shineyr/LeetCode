
/**
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */
public class NO_21 {
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
        ListNode(int x) { val = x; }
    }

    class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            ListNode p = l1, q = l2;

            ListNode head = null, r = null;
            while (p != null && q != null) {
                if (p.val < q.val) {
                    if (head == null) {
                        head = p;
                        r = head;
                    } else {
                        r.next = p;
                        r = r.next;
                    }

                    p = p.next;
                } else {
                    if (head == null) {
                        head = q;
                        r = head;
                    } else {
                        r.next = q;
                        r = r.next;
                    }
                    q = q.next;
                }
            }

            while (p != null) {
                if (head == null) {
                    head = p;
                    r = head;
                } else {
                    r.next = p;
                    r = r.next;
                }

                p = p.next;
            }

            while (q != null) {
                if (head == null) {
                    head = q;
                    r = head;
                } else {
                    r.next = q;
                    r = r.next;
                }
                q = q.next;
            }

            return head;
        }
    }
}
