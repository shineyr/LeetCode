/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        
        // Copy node and link to next pos of each node
        Node p = head;
        while(p != null) {
            Node newNode = new Node(p.val);
            
            newNode.next = p.next;
            p.next = newNode;
            
            p = newNode.next;
        }
        
        // Link random of new nodes with right pos
        p = head;
        while(p != null) {
            Node q = p.next;
            
            if (p.random == null) {
                q.random = null;
            } else {
                q.random = p.random.next;
            }
            
            p = q.next;
        }
        
        // Restore the original list and new list
        p = head;
        Node newHead = head.next, q = head.next;
        
        while(p.next != null) {
            p.next = q.next;
            
            p = q;
            
            q = q.next;
        }
        
        p.next = null;
        
        
        return newHead;
    }
    
    public Node copyRandomList1(Node head) {
        Map<Node, Node> nodeMap = new HashMap<>();
        
        Node p = head;
        while (p != null) {
            nodeMap.put(p, new Node(p.val));
            p = p.next;
        }
        
        for (Node node : nodeMap.keySet()) {
            Node newNode = nodeMap.get(node);
            newNode.next = nodeMap.get(node.next);
            newNode.random = nodeMap.get(node.random);
        }
        
        return nodeMap.get(head);
    }
}
