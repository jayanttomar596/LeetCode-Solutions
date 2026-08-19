class Solution {
    int dp[500][500] ;

    int solve(vector<int>& piles , int l , int r)
    {
        if (l == r) return piles[l] ;
        if (dp[l][r] != -1) return dp[l][r] ;
        int left = piles[l] - solve(piles , l+1 , r) ;
        int right = piles[r] - solve(piles , l , r-1) ;

        return dp[l][r] = max(left , right) ;
    }
public:
    bool stoneGame(vector<int>& piles) {
        memset(dp , -1 , sizeof(dp)) ;
        return solve(piles , 0 , piles.size() - 1) > 0 ;
    }
};