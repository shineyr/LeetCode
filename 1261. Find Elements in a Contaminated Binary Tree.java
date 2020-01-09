import java.util.HashSet;
import java.util.Set;

/**
 * 1261. Find Elements in a Contaminated Binary Tree
 *
 * Given a binary tree with the following rules:
 *
 *     root.val == 0
 *     If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
 *     If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
 *
 * Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
 *
 * You need to first recover the binary tree and then implement the FindElements class:
 *
 *     FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
 *     bool find(int target) Return if the target value exists in the recovered binary tree.
 */
public class NO_1261 {


    class TreeNode {
      int val;
      TreeNode left;
        TreeNode right;
      TreeNode(int x) { val = x; }
    }

    class FindElements {
        Set<Integer> elements = new HashSet<>();

        public FindElements(TreeNode root) {
            if (root != null) {
                root.val = 0;
                recoverTree(root);
            }
        }

        private void recoverTree(TreeNode root) {
            if (root == null) {
                return;
            }

            elements.add(root.val);

            if (root.left != null) {
                root.left.val = 2 * root.val + 1;
                recoverTree(root.left);
            }

            if (root.right != null) {
                root.right.val = 2 * root.val + 2;
                recoverTree(root.right);
            }
        }


        public boolean find(int target) {
            return elements.contains(target);
        }
    }

}
