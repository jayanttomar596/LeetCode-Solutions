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
    int findl(TreeNode* root)
    {
        int h = 0 ;
        while(root)
        {
            h++ ;
            root=root->left ;
        }
        return h ;
    }
    int findr(TreeNode* root)
    {
        int h = 0 ;
        while(root)
        {
            h++ ;
            root=root->right ;
        }
        return h ;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return NULL ;

        int l = findl(root) ;
        int r = findr(root) ;

        if (l == r) return (1 << l) - 1 ;

        return 1 + countNodes(root->left) + countNodes(root->right) ;
    }
};