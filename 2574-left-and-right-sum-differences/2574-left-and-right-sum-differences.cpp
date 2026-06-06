class Solution {
    // leftsum - rightsum 
    // leftsum - (totalsum - leftsum - curr) = 2*leftsum - totalsum + curr
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalsum = accumulate(nums.begin() , nums.end() , 0) ;

        int n = nums.size() ;
        vector<int> ans(n , 0) ;
        int sum = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            ans[i] = abs(2*sum - totalsum + nums[i]) ;
            sum += nums[i] ;
        }

        return ans ;
    }
};