class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;

        // for (long long i = 1000; i <= n; i *= 1000) {
        //     commas += (n - i + 1);
        // }

        for (long long i = 1000 ; i <= n ; i*=1000)
        {
            commas += (n-i+1) ;
        }

        return commas;
    }
};