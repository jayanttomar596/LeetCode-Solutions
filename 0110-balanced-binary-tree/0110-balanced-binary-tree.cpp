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
    int height(TreeNode* root)
    {
        if (!root) return 0 ;
        int l = height(root->left) ;
        int r = height(root->right) ;
        return max(l,r)+1 ;
    }

    bool solve(TreeNode* root)
    {
        if (!root) return true ;
        bool l = solve(root->left) ;
        bool r = solve(root->right) ;
        bool op = abs(height(root->left)-height(root->right)) <= 1 ;

        return (l&&r&&op) ;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root) ;
    }
};