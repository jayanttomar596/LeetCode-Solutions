class Solution {
    int gcd(int a , int b)
    {
        while(b != 0)
            {
                int r = a%b ;
                a = b ;
                b = r ;
            }

        return a ;
    }
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0 ;
        int n = nums.size() ;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = i+1 ; j < n ; j++)
            {
                long long g = gcd(nums[i] , nums[j]) ;
                long long temp = (1LL * nums[i] * nums[j]) / (g*g) ;
                ans = max(ans , temp) ;
            }
        }

        return ans ;
    }
};