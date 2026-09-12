class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10,0) ;
        for (int &i : digits) cnt[i]++ ;
        int ans = 0 ;

        for (int i = 100 ; i <= 998 ; i += 2)
        {
            vector<int> need(10,0) ;

            int a = i/100 ;
            int b = (i/10)%10 ;
            int c = i%10 ;
            need[a]++ ;
            need[b]++ ;
            need[c]++ ;

            bool ok = true ;
            for (int i = 0 ; i < 10 ; i++)
            {
                if (need[i] > cnt[i])
                {
                    ok = false ;
                    break ;
                }
            }

            if (ok)ans++ ;
        }

        return ans ;
    }
};