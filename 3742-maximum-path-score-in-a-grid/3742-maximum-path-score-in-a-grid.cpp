class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() ;

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(k+1 , -1))) ; // 3D dp bana liya 
        int startCost = (grid[0][0] != 0 ? 1 : 0) ;
        if (startCost > k) return -1 ;

        dp[0][0][startCost] = grid[0][0] ; // shuru me score jo grid ka hoga wahi hoga 

        for (int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < n ; j++)
                    {
                        int cellScore = grid[i][j] ;
                        int cellCost = grid[i][j] != 0 ? 1 : 0 ;

                        for (int c = 0 ; c <= k ; c++)
                            {
                                if (dp[i][j][c] == -1)
                                    continue ;

                                // Move Right - daye
                                if (j+1 < n)
                                {
                                    int newCost = c + (grid[i][j+1] != 0 ? 1 : 0) ;
                                    if(newCost <= k)
                                    {
                                        dp[i][j+1][newCost] = max(dp[i][j+1][newCost] , dp[i][j][c] + grid[i][j+1]) ;
                                    }
                                }

                                // Move Down - niiche
                                if (i+1 < m)
                                {
                                    int newCost = c + (grid[i+1][j] != 0 ? 1 : 0) ;
                                    if (newCost <= k)
                                    {
                                            dp[i+1][j][newCost] = max(dp[i+1][j][newCost] , dp[i][j][c] + grid[i+1][j]) ;
                                    }
                                }
                            }
                    }
            }

        int ans = -1 ;
        for (int c = 0 ; c <= k ; c++)
            {
                ans = max(ans , dp[m-1][n-1][c]) ;
            }

        return ans ;
    }
};