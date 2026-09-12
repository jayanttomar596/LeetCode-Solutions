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
    int ans = 0 ;

    // sum , no of nodes 
    pair<int , int> solve(TreeNode* root)
    {
        if (!root) return {0 , 0};

        pair<int , int> l = solve(root->left) ;
        pair<int , int> r = solve(root->right) ;

        int l_sum = l.first ;
        int r_sum = r.first ;
        int l_node = l.second ;
        int r_node = r.second ;

        if ((l_sum + r_sum + root->val)/(l_node + r_node + 1) == root->val)
        {
            ans++ ;
        }

        return { l_sum + r_sum + root->val   ,   l_node + r_node + 1 } ;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        solve(root) ;

        return ans ;
    }
};