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
    vector<int> arr;
    
    void back(TreeNode* cur)
    {
        if(cur==NULL) return;
        back(cur->left);
        arr.push_back(cur->val);
        back(cur->right);
    }
    
    bool isValidBST(TreeNode* root) {
        back(root);
        for(int i=1;i<arr.size();i++)if(arr[i-1]>=arr[i]) return false;
        return true;
    }
};