class Solution {
public:
    int minRotations(int n, string s) {
        int curr = s[n-1] - '0' ;
        vector<int> suff(n) ;
        suff[n-1] = 0 ;
        int rt = 0 ;

        for (int i = n-2 ; i >= 0 ; i--)
        {
            int num = s[i]-'0' ;
            rt += min({10-curr+num , abs(curr-num) , curr + 10-num}) ;
            curr = num ;
            suff[i] = rt ;
        }

        curr = 0 ;
        rt = 0 ;

        int ans = INT_MAX ;
        for (int i = 0 ; i < n ; i++)
        {
            // if i = k 
            int op1 = 0; 
            op1 += rt ;
            op1 += min({10-curr+(s[n-1]-'0') , abs(curr-(s[n-1]-'0')) , curr + 10-(s[n-1]-'0')}) ;
            op1 += suff[i] ;

            ans = min(ans , op1) ;
            int num = s[i]-'0' ;
            rt += min({10-curr+num , abs(curr-num) , curr + 10-num}) ;
            curr = num ;
        }

        ans = min(ans , rt) ;
        return ans ;
    }
};