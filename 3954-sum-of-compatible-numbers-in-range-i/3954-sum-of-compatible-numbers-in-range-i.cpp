class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int cnt = 0 ;

        for (int i = max(n-k,1) ; i <= n+k ; i++)
            {
                if ((i & n) == 0)
                {
                    cnt += i ;
                }
            }

        return cnt ;
    }
};