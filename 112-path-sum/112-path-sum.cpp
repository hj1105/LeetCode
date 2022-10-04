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
    //    printf("%d %d\n", root->val, targetSum);
        if(root==NULL) return false;
        if(root->left == NULL && root->right == NULL) return targetSum - root->val == 0;
        int ret=0;
        if(root->left != NULL) ret|=hasPathSum(root->left, targetSum - root->val);
        if(root->right != NULL) ret|=hasPathSum(root->right, targetSum - root->val);
        return ret>0;
    }
};