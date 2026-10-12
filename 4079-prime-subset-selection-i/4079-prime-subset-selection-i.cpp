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
                for (int j = i*i ; j <= n ; j+= i)
                {
                    isprime[j] = false ;
                }
            }
        }

        int sum = 0 ;

        for (int i = 2 ; i <= n ; i++)
        {
            if (isprime[i])
            {
                if (sum + i <= s)
                {
                    sum += i ;
                    ans.push_back(i) ;
                }
                else
                {
                    break ;
                }
            }
        }

        return ans ;
    }
};