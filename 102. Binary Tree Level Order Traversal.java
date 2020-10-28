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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        recursion(root, 0, ans);
        
        return ans;
    }
    
    private void recursion(TreeNode node, int level, List<List<Integer>> levels) {
        if (node == null) {
            return;
        }
        
        if (level == levels.size()) {
            levels.add(new ArrayList<Integer>());
        }
        
        List<Integer> curLevel = levels.get(level);
        curLevel.add(node.val);
        
        recursion(node.left, level + 1, levels);
        recursion(node.right, level + 1, levels);
    }
        
    public List<List<Integer>> levelOrder1(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        if (root == null) {
            return ans;
        }
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        queue.add(null);
        
        List<Integer> curLevel = new ArrayList<>();
        while(!queue.isEmpty()) {
            TreeNode node = queue.poll();
            
            if (node == null) {
                ans.add(curLevel);
                
                if (queue.isEmpty()) {
                    break;
                }
                
                curLevel = new ArrayList<Integer>();
                
                // The tag for end of cur level
                queue.add(null);
                
            } else {
                curLevel.add(node.val);
                
                if (node.left != null) {
                    queue.add(node.left);
                }
                
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
            
        return ans;
    }

}
