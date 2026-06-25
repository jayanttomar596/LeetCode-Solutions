class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n , 0) ;

        int prev2 = nums[0] ;
        int prev1 = prev2;
        if (n > 1)
            prev1 = max(nums[0] , nums[1]) ;

        for (int i = 2 ; i < n ; i++)
        {
            int inc = prev2 + nums[i] ;
            int exc = prev1 ;
            int ans = max(inc,exc) ;
            prev2 = prev1 ;
            prev1 = ans ;
        }

        return prev1 ;
    }
};