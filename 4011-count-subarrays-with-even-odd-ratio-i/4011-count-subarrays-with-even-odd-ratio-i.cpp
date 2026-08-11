class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int ans = 0 ;

        int n = nums.size() ;
        for (int i = 0 ; i < n ; i++)
        {
            int even = 0 ;
            int odd = 0 ;
    
            for (int j = i ; j < n ; j++)
            {
                if (nums[j]&1) odd++ ;
                else even++ ;

                if (odd > 0)
                {
                    if (even*b <= odd*a) ans++ ;
                }            
            }
        }
        return ans;
    }
};