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
    // 0 : 루트 선택 + 왼/오 1 : 루트 + 왼 + 오
    int ans=-2e9;
    
    pair<int,int> back(TreeNode* cur){
        if(cur==nullptr){
            return {-2e9,-2e9};
        }
        if(cur->left==nullptr && cur->right==nullptr){
            if(cur->val>ans) ans=cur->val;
            return {cur->val,0};
        }
        pair<int,int> l=back(cur->left);
        pair<int,int> r=back(cur->right);
        pair<int,int> ret={cur->val,cur->val};
        if(cur->left) ret.first=max(ret.first,l.first+cur->val);
        if(cur->right) ret.first=max(ret.first,r.first+cur->val);
        if(cur->left && cur->right) ret.second=max(ret.second,l.first+r.first+cur->val);
        if(ret.first>ans) ans=ret.first;
        if(ret.second>ans) ans=ret.second;
        return ret;
    }
    
    int maxPathSum(TreeNode* root) {
        back(root);
        return ans;
    }
};