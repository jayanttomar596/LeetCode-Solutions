class Solution {
    vector<int> dp ;
    int solve(vector<int>& nums , int i)
    {
        if (i >= nums.size()-1) return 0 ;
        int ans = INT_MAX ;

        if (dp[i] != -1) return dp[i] ;

        for (int jump = 1 ; jump <= nums[i] ; jump++)
        {
            int result = solve(nums , i+jump) ;
            if (result != INT_MAX)
                ans = min(ans , 1 + result) ;
        }
        return dp[i] = ans ;
    }
public:
    int jump(vector<int>& nums) {
        dp.assign(nums.size() , -1) ;
        return solve(nums , 0) ;
    }
};