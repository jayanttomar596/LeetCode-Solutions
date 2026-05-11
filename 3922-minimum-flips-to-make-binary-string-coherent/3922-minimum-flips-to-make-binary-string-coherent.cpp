class Solution {
public:
    int minFlips(string s) {
        // 3 case valid 
        // no middle 1 that means 1 only at ends , only one 1 , or all 1

        int n = s.length() ;
        if (n < 3) return 0 ;

        int cnt0 = count(s.begin() , s.end() , '0') ;
        int cnt1 = n - cnt0 ;
        int res1 = cnt0 ; // all one
        int res2 = max(cnt1 - 1 , 0) ;// one one
        int res3 = cnt1 - (s[0] - '0') - (s[n-1] - '0') ; //except at end if 1 exist 

        return min({res1 , res2 , res3}) ;
    }
};