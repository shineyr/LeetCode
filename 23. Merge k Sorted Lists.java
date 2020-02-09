import java.util.ArrayList;
import java.util.List;

/**
 * 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */
public class NO_23 {
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
        ListNode(int x) { this.val = x; }
    }
    class Solution {
        public ListNode mergeKLists(ListNode[] lists) {
            if (lists.length <= 0) {
                return null;
            }

            if (lists.length == 1) {
                return lists[0];
            }

            List<ListNode> mergedLists = new ArrayList<>();
            int i=0, j = lists.length - 1;
            while (i<j) {
                mergedLists.add(mergeLists(lists[i], lists[j]));
                ++i;
                --j;
            }

            if (i == j) {
                mergedLists.add(lists[i]);
            }

            return mergeKLists((ListNode[]) mergedLists.toArray(new ListNode[]{}));
        }

        private ListNode mergeLists(ListNode l1, ListNode l2) {
            if (l1 == null) {
                return l2;
            }

            if (l2 == null) {
                return l1;
            }

            ListNode p = l1, q = l2, head = null;
            if (l1.val < l2.val) {
                head = l1;
                p = l1.next;
            } else {
                head = l2;
                q = l2.next;
            }

            ListNode r = head;
            while (p != null && q != null) {
                if (p.val < q.val) {
                    r.next = p;
                    r = p;

                    p = p.next;
                } else {
                    r.next = q;
                    r = q;

                    q = q.next;
                }
            }

            while (p != null) {
                r.next = p;
                r = p;

                p = p.next;
            }

            while (q != null) {
                r.next = q;
                r = q;

                q = q.next;
            }

            return head;
        }

    }
}
