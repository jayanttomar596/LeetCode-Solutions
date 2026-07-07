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
    int minswap(vector<int>& nums)
    {
        int n = nums.size() ;

        vector<int> sorted = nums ;
        sort(sorted.begin() , sorted.end()) ;

        unordered_map<int , int> targetIndex ;

        for (int i = 0 ; i < n ; i++)
        {
            targetIndex[sorted[i]] = i ;
        }

        vector<bool> vis(n , false) ;

        int swaps = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            if (vis[i] || targetIndex[nums[i]] == i) continue ;

            int cyclen = 0 ;
            int j = i ;

            while(!vis[j])
            {
                vis[j] = true ;
                j = targetIndex[nums[j]] ;
                cyclen++ ;
            }

            swaps += cyclen - 1 ;
        }

        return swaps ;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root) ;

        int op = 0 ;

        while(!q.empty())
        {
            int size = q.size() ;
            vector<int> level ;

            for (int i = 0 ; i < size ; i++)
            {
                TreeNode* node = q.front() ;
                q.pop() ;

                level.push_back(node->val) ;

                if (node->left) q.push(node->left) ;
                if (node->right) q.push(node->right) ;
            }
            op += minswap(level) ;
        }

        return op ;
    }
};