class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size() ;
        int m = t.size() ;

        if (n > m) return false ;

        vector<int> pre(n+1,m) ;
        vector<int> suff(n+1,-1) ;

        pre[0] = 0 ;

        int j = 0 ; 
        for (int i = 0 ; i < n ; i++)
        {
            while(j < m && t[j] != s[i])
                j++ ;
            if (j == m) break ;
            j++ ;
            pre[i+1] = j ;
        }

        if (pre[n] != m) return true ;

        suff[n] = m ;
        j= m-1 ;

        for (int i = n-1 ; i >= 0 ; i--)
        {
            while(j >= 0 && t[j] != s[i]) j-- ;

            if (j < 0) break ;
            suff[i] = j ;
            j-- ;
        }

        for (int i = 0; i < n; i++) 
        {
            int left = pre[i];
            int right = suff[i + 1];

            if (left < right)
                return true;
        }

        return false;
    }
};