class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size() ;
        int zeros = 0 ;

        for (int &x : nums)
            {
                if (x == 0)
                {
                    zeros++ ;
                }
            }

        int ans = 0 ;
        for (int i = n-zeros ; i < n ; i++)
            {
                if (i >= 0 && nums[i] != 0)
                {
                    ans++ ;
                }
            }

        return ans ;
    }
};