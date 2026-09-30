class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size() ;

        vector<long long> b(n) ;

        long long original = 0 ;

        for (int i = 0 ; i < n ; i++) 
        {
            if (i % 2 == 0)
                b[i] = nums[i] ;
            else
                b[i] = -1LL * nums[i] ;

            original += b[i] ;
        }

        const long long INF = 4e18 ;

        long long odd = INF ;
        long long even = INF ;

        long long minEven = INF ;

        for (int i = 0 ; i < n ; i++) 
        {
            long long newOdd = b[i] ;

            long long newEven = INF ;

            if (odd != INF) 
            {
                newEven = odd + b[i] ;
            }

            if (even != INF) 
            {
                newOdd = min(newOdd, even + b[i]) ;
            }

            odd = newOdd ;
            even = newEven ;

            minEven = min(minEven, even) ;
        }


        long long answer = original;

        if (minEven < 0) 
        {
            answer += -2LL * minEven ;
        }

        return answer ;
    }
};