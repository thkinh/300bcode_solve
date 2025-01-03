/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isFound = false;
        int sum = targetSum;
        if(root == NULL ){
            return false;
        }
        if(root->left == NULL && root->right == NULL){ //check leaf node
            if(sum - root->val == 0){
                return true;
            }
            return false;
        }
        sum -= root->val;
        if(root->left != NULL){
           isFound = hasPathSum(root->left, sum);
        }
        if(root->right != NULL && isFound == false){
           isFound =  hasPathSum(root->right, sum);
        }
        return isFound;
    }
};