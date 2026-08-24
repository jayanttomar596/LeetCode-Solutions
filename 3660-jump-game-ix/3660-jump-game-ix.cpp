class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> suff(n);
        suff[n-1] = nums[n-1] ;

        for (int i = n-2 ; i >= 0 ; i--)
        {
            suff[i] = min(nums[i] , suff[i+1]) ;
        }

        vector<int> ans(n) ;

        int start = 0 ;
        int maxvalue = nums[0] ;

        for (int i = 0 ; i < n-1 ; i++)
        {
            maxvalue = max(maxvalue , nums[i]) ;

            if (maxvalue <= suff[i+1]) 
            {
                for (int j = start ; j <= i ; j++)
                {
                    ans[j] = maxvalue ;
                }

                start = i+1 ;
                maxvalue = nums[start] ;
            }
        }

        for (int i = start ; i < n ; i++)
        {
            maxvalue = max(maxvalue , nums[i]) ;
        }

        for (int i = start ; i < n ; i++)
        {
            ans[i] = maxvalue ;
        }

        return ans ;
    }
};