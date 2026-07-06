class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size() ;

        int ans = 0 ;
        int maxLeft = nums[0] ;

        for (int j = k ; j < n ; j++)
        {
            maxLeft = max(maxLeft , nums[j-k]) ;
            ans = max(ans , maxLeft + nums[j]) ;
        }

        return ans ;
    }
};