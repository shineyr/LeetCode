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
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new ArrayList<TreeNode>();
        }
        
        return generateTrees(1, n);
    }
    
    private List<TreeNode> generateTrees(int beg, int end) {
        List<TreeNode> trees = new ArrayList<TreeNode>();

        if (beg > end) {
            trees.add(null);
            return trees;
        }
        
        for (int r = beg; r <= end; ++r) {
            List<TreeNode> leftTrees = generateTrees(beg, r - 1);
            List<TreeNode> rightTrees = generateTrees(r + 1, end);
            
            for(TreeNode leftTree : leftTrees) {
                for (TreeNode rightTree : rightTrees) {
                    TreeNode root = new TreeNode(r, leftTree, rightTree);
                    trees.add(root);
                }
            }
        }
        
        return trees;
    }
}
