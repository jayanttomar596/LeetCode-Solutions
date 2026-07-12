class Solution {
private :
    int r ;
    int c ;
    int target ;
    vector<pair<int , int>> cells ;

    long long count(const vector<string>& grid)
    {
        vector<vector<long long>> dp(r , vector<long long>(c , 0)) ;
        dp[0][0] = 1 ;

        for (int i = 0 ; i < r ; i++)
            {
                for (int j = 0 ; j < c ; j++)
                    {
                        if (grid[i][j] == '#') continue ;

                        if (i > 0) dp[i][j] += dp[i-1][j] ;
                        if (j > 0) dp[i][j] += dp[i][j-1] ;
                    }
            }
        return dp[r-1][c-1] ;
    }


    bool dfs(int index , vector<string>& grid)
    {
        long long curr = count(grid) ;

        if (curr == target) return true ;
        if (curr < target) return false ;
        if (index == cells.size()) return false ;

        int row = cells[index].first ;
        int col = cells[index].second ;

        grid[row][col] = '#' ;
        if (dfs(index+1 , grid)) return true ;

        grid[row][col] = '.' ;
        if (dfs(index+1 , grid)) return true ;

        return false ;
    }
    
public:
    vector<string> createGrid(int m, int n, int k) {
        r = m ;
        c = n ;
        target = k ;

        if (m == 1 || n == 1)
        {
            if (k == 1) return vector<string>(m , string(n,'.')) ;
            return {} ;
        }

        vector<string> grid(m , string(n,'.')) ;

        for(int i = 0 ; i < m ; i++)
            {
                for (int j = 0 ; j < n ; j++)
                    {
                        if (i == 0 && j== 0) continue ;
                        if (i == m-1 && j == n-1) continue ;

                        cells.push_back({i ,j}) ;
                    }
            }

        reverse(cells.begin(),cells.end()) ;

        if (dfs(0,grid)) return grid ;

        return {} ;
    }
};