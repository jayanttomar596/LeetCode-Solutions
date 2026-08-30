class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ;

        for (int removal = -1 ; removal < n ; removal++)
            {
                vector<int> arr ;

                for (int i = 0 ; i < n ; i++)
                    {
                        if (i != removal) arr.push_back(nums[i]);
                    }

                int m = arr.size() ;
                if (m < 2) continue ;
                vector<int> suff(m) ;
                suff[m-1] = arr[m-1] ;

                for (int i = m-2 ; i >= 0 ; i--)
                    {
                        suff[i] = gcd(suff[i+1] , arr[i]) ;
                    }

                int left = 0 ;
                int curr = 0 ;
                for (int i = 0 ; i < m-1 ; i++)
                    {
                        left = gcd(left , arr[i]) ;
                        if (left == suff[i+1]) curr++ ;
                    }
                
                ans = max(ans , curr) ;
            }
        
        return ans ;
    }
};