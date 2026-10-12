class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        if (n < 2 || s < 2) return {} ;
        vector<int> ans ;

        vector<bool> isprime(n+1,true) ;
        isprime[0] = isprime[1] = false ;

        for (int i = 2 ; 1LL*i*i <= n ; i++)
        {
            if (isprime[i])
            {
                for (int j = i*i ; j <= n ; j += i)
                {
                    isprime[j] = false ;
                }
            }
        }

        int sum = 0 ;

        for (int p = 2 ; p <= n ; p++)
        {
            if (isprime[p])
            {
                if (sum + p > s) break ;
                sum += p ;
                ans.push_back(p) ;
            }
        }
        return ans ;
    }
};