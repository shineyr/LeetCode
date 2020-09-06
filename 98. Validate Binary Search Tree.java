/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        
        double inOrder = - Double.MAX_VALUE;
        
        while(!stack.isEmpty() || root != null) {
            while(root != null) {
                stack.push(root);
                root = root.left;
            }
            
            root = stack.pop();
            
            if (root.val <= inOrder) {
                return false;
            }
            
            inOrder = root.val;
            
            root = root.right;
        }
        
        return true;
    }
    
    
    
    
    LinkedList<TreeNode> list = new LinkedList();
    LinkedList<Integer> lowers = new LinkedList<Integer>(), uppers = new LinkedList<Integer>();
    
    public boolean isValidBST2(TreeNode root) {
        Integer lower = null, upper = null, val;
        
        update(root, lower, upper);
        
        while(!list.isEmpty()) {
            root = list.poll();
            lower = lowers.poll();
            upper = uppers.poll();
            
            if (root == null) {
                continue;
            }
            
            val = root.val;
            
            if (lower != null && val <= lower) {
                return false;
            }
            
            if (upper != null && val >= upper) {
                return false;
            }
            
            update(root.left, lower, val);
            update(root.right, val, upper);
        }
        
        return true;
    } 
    
    private void update(TreeNode root, Integer lower, Integer upper) {
        list.add(root);
        lowers.add(lower);
        uppers.add(upper);
    }
    
    
    public boolean isValidBST1(TreeNode root) {
        return check(root, null, null);
    }
    
    private boolean check(TreeNode root, Integer lower, Integer upper) {
        if (root == null) {
            return true;
        }
        
        int val = root.val;
        
        if (lower != null && val <= lower) {
            return false;
        }
        
        if (upper != null && val >= upper) {
            return false;
        }
        
        if (!check(root.left, lower, val)) {
            return false;
        }
        
        if (!check(root.right, val, upper)) {
            return false;
        }
        
        return true;
    }
}
