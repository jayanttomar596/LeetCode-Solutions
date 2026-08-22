class Solution {
    vector<int> suff ;
    int dp[101][101] ;

    int solve(vector<int>& piles , int i , int m)
    {
        int n = piles.size() ;

        if (i >= n) return 0 ;

        if (dp[i][m] != -1) return dp[i][m] ;

        int ans = 0 ;

        for (int x = 1 ; x <= min(2*m , n-i) ; x++)
        {
            int nextM = max(m , x) ;

            int total = suff[i] ;

            int opp = solve(piles , i+x , nextM) ;

            int curr = total - opp ;
            ans = max(ans , curr) ;
        }
        return dp[i][m] = ans ;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size() ;
        suff.resize(n+1 , 0) ;

        for (int i = n-1 ; i >= 0 ; i--)
        {
            suff[i] = suff[i+1] + piles[i] ;
        }

        memset(dp , -1 , sizeof(dp)) ;

        return solve(piles , 0 , 1) ;
    }
};