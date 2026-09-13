class Solution {
    vector<int> dp ;
    int solve(int n)
    {
        if (n == 0) return 0 ;
        if (dp[n] != -1) return dp[n] ;
        int ans = INT_MAX ;

        for (int k = 1 ; k * (k+1) /2 <= n ; k++)
        {
            int pt = k*(k+1) / 2 ;

            if (pt == n) ans = min(ans , k) ;
            else ans = min(ans , solve(n-pt) + k + 1) ;
        }
        return dp[n] = ans ;
    }
public:
    int minDays(int n) {
        dp.assign(n+1 , -1) ;
        return solve(n) ;
    }
};