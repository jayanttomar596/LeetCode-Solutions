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
    pair<bool,int> solve(TreeNode* root)
    {
        if (!root) return {true,0};
        pair<bool,int> l = solve(root->left) ;
        pair<bool,int> r = solve(root->right) ;
        bool op = abs(l.second - r.second) <= 1 ;

        return {(l.first && r.first && op) , max(l.second , r.second) +1} ;
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).first ;
    }
};