class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size() ;

        vector<vector<int>> children(n) ;
        for (int i = 1 ; i < n ; i++)
        {
            children[parent[i]].push_back(i) ;
        }

        vector<int> depth(n) ;
        depth[0] = 1 ;

        int h = 1 ;
        queue<int> q ;
        q.push(0) ;

        while(!q.empty())
        {
            int node = q.front() ;
            q.pop() ;

            for (int child : children[node])
            {
                depth[child] = depth[node] + 1 ;
                h = max(h , depth[child]) ;
                q.push(child) ;
            }
        }

        long long ans = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            ans += 1LL * nums[i] * (h - depth[i] + 1) ;
        }

        return ans ;
    }
};