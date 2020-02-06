/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class NO_2 {
    private class Solution {
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
            ListNode p = l1, q = l2, head = null, r = null;
            int carry = 0;
            while (p != null && q != null) {
                int sum = p.val + q.val + carry;

                ListNode node = new ListNode(sum % 10);
                carry = sum / 10;

                if (head == null) {
                    head = node;
                    r = head;
                } else {
                    r.next = node;
                    r = node;
                }

                p = p.next;
                q = q.next;
            }

            while (p != null) {
                int sum = p.val + carry;

                ListNode node = new ListNode(sum % 10);
                carry = sum / 10;

                if (head == null) {
                    head = node;
                    r = head;
                } else {
                    r.next = node;
                    r = node;
                }

                p = p.next;
            }

            while (q != null) {
                int sum = q.val + carry;

                ListNode node = new ListNode(sum % 10);
                carry = sum / 10;

                if (head == null) {
                    head = node;
                    r = head;
                } else {
                    r.next = node;
                    r = node;
                }

                q = q.next;
            }

            if (carry != 0) {
                ListNode node = new ListNode(carry);

                if (head == null) {
                    head = node;
                } else {
                    r.next = node;
                }
            }

            return head;
        }


    }

    private class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
}


