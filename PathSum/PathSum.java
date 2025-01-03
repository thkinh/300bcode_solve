/*
 //Definition for a binary tree node.
 public class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
}

*/
class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        boolean isFound = false;
        int sum = targetSum;

        if(root == null ){
            return false;
        }
        if(root.left == null && root.right == null){ //check leaf node
            if(sum - root.val == 0){
                return true;
            }
            return false;
        }
        sum -= root.val;
        if(root.left != null){
           isFound = hasPathSum(root.left, sum);
        }
        if(root.right != null && isFound == false){
           isFound =  hasPathSum(root.right, sum);
        }
        return isFound;
    }
}