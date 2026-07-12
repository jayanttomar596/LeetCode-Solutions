class Solution {
public:
    const long long MOD = 1000000007LL ;
    int minimumCost(vector<int>& nums, int k) {

        long long ans = 0 ;
        long long x = k ;
        long long op = 0 ;

        for (long long y : nums)
            {
                if (x < y)
                {
                    long long left = (y - x + k - 1)/k ;
                    __int128 cost = (__int128)left*(2LL*op + left + 1)/2 ;

                    ans = (ans + (long long)(cost%MOD))%MOD ;
                    x += left * k ;
                    op += left ;
                }
                x -= y ;
            }

        ans%=MOD ;

        return (int)(ans) ;
    }
};