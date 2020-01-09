/**
 * 1290. Convert Binary Number in a Linked List to Integer
 *
 * Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
 *
 * Return the decimal value of the number in the linked list.
 */
public class NO_1290 {
    /**
     * Definition for singly-linked list.
     */
     class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
     }

    class Solution {
        public int getDecimalValue(ListNode head) {
            int count = 0;
            ListNode p = head;
            while (p != null) {
                ++count;

                p = p.next;
            }

            int value = 0;
            p = head;
            while (p != null) {
                value += p.val * Math.pow(2, count - 1);
                --count;
                p = p.next;
            }

            return value;
        }
    }
}
