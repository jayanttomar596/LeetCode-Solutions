class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n) ;
        reverse(s.begin() , s.end()) ;

        int r = stoi(s) ;
        // r is the reversed number

        int maxi = max(n,r) ;
        int mini = min(n,r) ;

        vector<bool> prime(maxi+1 , true) ;

        prime[1] = false ;
        prime[0] = false ;

        for (int i = 2 ; i * i <= maxi ; i++)
        {
            if (prime[i])
            {
                for (int j = i*i ; j <= maxi ; j+=i)
                {
                    prime[j] = false ;
                }
            }
        }

        int ans = 0 ;
        for (int i = mini ; i <= maxi ; i++)
        {
            if (prime[i]) ans += i ;
        }

        return ans ;
    }
};