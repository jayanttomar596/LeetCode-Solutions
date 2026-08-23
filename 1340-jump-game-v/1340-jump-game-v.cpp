class Solution {
    int dfs(vector<int>& arr , int d , int i , vector<int>& dp)
    {
        if (dp[i] != -1) return dp[i] ;

        int n = arr.size() ;
        int ans = 1 ;

        for (int j = i+1 ; j <= min(i+d , n-1) ; j++)
        {
            if (arr[j] >= arr[i]) break ;
            ans = max(ans , 1 + dfs(arr , d , j , dp)) ;
        }

        for (int j = i-1 ; j >= max(i-d,0) ; j--)
        {
            if (arr[j] >= arr[i]) break ;
            ans = max(ans , 1 + dfs(arr , d , j , dp)) ;
        }

        return dp[i] = ans ;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size() ;
        vector<int> dp(n,-1) ;
        int ans = 1 ;

        for (int i = 0 ; i < n ; i++)
        {
            ans = max(ans , dfs(arr , d , i , dp)) ;
        }
        return ans ;
    }
};