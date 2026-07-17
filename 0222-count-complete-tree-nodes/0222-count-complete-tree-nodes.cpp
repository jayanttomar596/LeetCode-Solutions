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
    void inorder(TreeNode* root, int &count) {
        // If current node is NULL, stop processing
        if (root == NULL) {
            return;
        }
        // Increment count for current node
        count++;
        // Recursively count nodes in the left subtree
        inorder(root->left, count);
        // Recursively count nodes in the right subtree
        inorder(root->right, count);
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        // Variable to store node count
        int count = 0;
        // Perform inorder traversal to count nodes
        inorder(root, count);
        // Return total number of nodes
        return count;
    }
};