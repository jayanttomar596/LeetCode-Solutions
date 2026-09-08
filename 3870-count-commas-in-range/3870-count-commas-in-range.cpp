
class Solution {
    int solve(int n)
    {
        int digits = 0 ;
        int temp = n ;

        while(temp != 0)
            {
                digits++ ;
                temp /= 10 ;
            }

        return ((digits-1)/3) ;
    }
    
public:
    int countCommas(int n) {
        int ans = 0 ;
        for (int i = 1 ; i <= n ; i++)
            {
                ans += solve(i) ;
            }

        return ans ;
    }
};