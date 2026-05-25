class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size() ;

        vector<bool> dp(n , false) ;
        dp[0] = true ;

        int reachableCount = 0 ;

        for (int i = 1 ; i < n ; i++)
        {
            if (i - minJump >= 0 && dp[i - minJump])
            {
                reachableCount++ ;
            }

            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
            {
                reachableCount-- ;
            }

            if (s[i] == '0' && reachableCount > 0)
            {
                dp[i] = true ;
            }
        }

        return dp[n-1] ;
    }
};