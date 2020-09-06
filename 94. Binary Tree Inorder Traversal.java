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
    public List<Integer> inorderTraversal(TreeNode root) {
        Stack<TreeNode> stack = new Stack();
        List<Integer> inorderList = new ArrayList<>();
        
        while(!stack.isEmpty() || root != null) {
            while(root != null) {
                stack.push(root);
                root = root.left;
            }
            
            root = stack.pop();
            
            inorderList.add(root.val);
            
            root = root.right;
        }
        
        return inorderList;
    }
    
    
    public List<Integer> inorderTraversal1(TreeNode root) {
        List<Integer> inorderList = new ArrayList<>();
        
        inorderTraversal(root, inorderList);
        return inorderList;
    }
    
    private void inorderTraversal(TreeNode root, List<Integer> inorderList) {
        if (root == null) {
            return;
        }
        
        inorderTraversal(root.left, inorderList);
        inorderList.add(root.val);
        inorderTraversal(root.right, inorderList);
    }
}
