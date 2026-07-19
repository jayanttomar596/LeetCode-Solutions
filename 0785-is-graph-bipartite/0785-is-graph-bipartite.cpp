class Solution {
    bool dfs(int i , int col , vector<int>& v , vector<vector<int>>& graph)
    {
        v[i] = col ;

        for (auto it : graph[i])
        {
            if (v[it] == -1)
            {
                if (dfs(it , !col , v , graph) == false) return false;
            }
            else if (v[it] == col)
            {
                return false ;
            }
        } 
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> v(n,-1) ;

        for (int i = 0 ; i < n-1 ; i++)
        {
            if (v[i] == -1)
            {
                if (dfs(i,0,v,graph) == false)
                {
                    return false ;
                }
            }
        }

        return true ;
    }
};