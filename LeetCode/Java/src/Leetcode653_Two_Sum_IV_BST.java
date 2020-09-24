import java.util.HashSet;

public class Leetcode653_Two_Sum_IV_BST {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    public boolean findTarget(TreeNode root, int k) {
        HashSet<Integer> set = new HashSet<>();
        return find(root,k,set);
    }

    private boolean find(TreeNode root, int k, HashSet<Integer> set) {
        if(root == null) return false;
        if(set.contains(k - root.val)){
            return true;
        }
        set.add(root.val);
        return find(root.left,k,set) || find(root.right,k,set);
    }
}
