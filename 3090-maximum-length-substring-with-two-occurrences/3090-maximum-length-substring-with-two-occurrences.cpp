class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length() ;

        vector<int> v(26,0) ;
        int len = 0 ;

        int l = 0 , r = 0 ;

        for (r = 0 ; r < n ; r++)
        {
            int index = s[r] - 'a' ;
            v[index]++ ;
            if (v[index] > 2)
            {
                while(v[index] > 2)
                {
                    v[s[l]-'a']-- ;
                    l++ ;
                }
            }
            len = max(len , r-l+1) ;
        }

        return len ;
    }
};