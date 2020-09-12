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
    //  Morris Traversal
    // https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
    
    public void recoverTree(TreeNode root) {
        TreeNode prev = null, first = null, second = null;
        while(root != null) {
            if (root.left != null) {
                TreeNode temp = root.left;
                
                // Find the most right node of left child tree
                while(temp.right != null && temp.right != root) {
                    temp = temp.right;
                }
                
                if (temp.right == null) {
                    temp.right = root;
                    
                    root = root.left;
                } else {
                    temp.right = null;
                    
                    //visit root.val
                    
                    if (first == null && prev != null && prev.val >= root.val) {
                        first = prev;
                    }
                    
                    if (first != null && prev != null && prev.val >= root.val) {
                        second = root;
                    }
                    
                    prev = root;
                    
                    root = root.right;
                }
            } else {
                // visit root.val
                
                if (first == null && prev != null && prev.val >= root.val) {
                    first = prev;
                }

                if (first != null && prev != null && prev.val >= root.val) {
                    second = root;
                }

                prev = root;

                root = root.right;
            }
        }
        
        if (first != null && second != null) {
            int temp = first.val;
            first.val = second.val;
            second.val = temp;
        }
    }
    
    
    
    TreeNode prev = null, first = null, second = null;
    public void recoverTree1(TreeNode root) {
        if (root == null) {
            return;
        }
        
        inorder(root);
        
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }
    
    private void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        
        inorder(root.left);
        if (first == null && prev != null && prev.val >= root.val) {
            first = prev;
        }
        
        if (first != null && prev != null && prev.val >= root.val) {
            second = root;
        }
        
        prev = root;
        inorder(root.right);
    }
}
