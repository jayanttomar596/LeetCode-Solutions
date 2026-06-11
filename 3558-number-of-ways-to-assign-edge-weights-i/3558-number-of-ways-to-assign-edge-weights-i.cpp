class Solution {
    const int MOD = 1e9 + 7 ;
    vector<vector<int>> adj ;
    int maxDepth = 0 ;

    void dfs(int node , int parent , int depth)
    {
        maxDepth = max(maxDepth , depth) ;
        for (int child : adj[node])
        {
            if (child != parent)
            {
                dfs(child , node , depth+1) ;
            }
        }
    }

    long long modPow(long long base , long long exp)
    {
        long long result = 1 ;
        while(exp > 0)
        {
            if (exp % 2)
                result = (result*base) % MOD ;
            base = (base * base) % MOD ;
            exp /= 2 ;
        }

        return result ;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1 ;
        adj.assign(n+1 , {}) ;

        for (auto& e : edges)
        {
            int u = e[0] , v = e[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        dfs(1 , -1 , 0) ;

        return modPow(2 , maxDepth-1) ;
    }
};