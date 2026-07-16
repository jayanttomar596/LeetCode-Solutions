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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int,vector<int> >> nodes ;
        queue<pair<TreeNode* ,pair<int , int>>> q ;
        vector<vector<int>> ans ;

        if (!root) return ans ;
        q.push({root , {0,0}}) ;
        while(!q.empty())
        {
            auto temp = q.front() ;
            q.pop() ;

            TreeNode* node = temp.first ;
            int x = temp.second.first ;
            int y = temp.second.second ;

            nodes[x][y].push_back(node->val) ;

            if (node->left) q.push({node->left , {x-1,y+1}}) ;
            if (node->right) q.push({node->right , {x+1 , y+1}}) ;
        }

        for (auto &i : nodes)
        {
            vector<int> col ;
            for (auto &j : i.second)
            {
                sort(j.second.begin() , j.second.end()) ;

                for (int val : j.second) col.push_back(val) ;
            }

            ans.push_back(col) ;
        }

        return ans ;
    }
};