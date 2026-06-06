class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size() ;

        vector<int> left(26,n) , right(26 , -1) ;

        for (int i = 0 ; i < n ; i++)
        {
            left[s[i] - 'a'] = min(left[s[i] - 'a'] , i) ;
            right[s[i] - 'a'] = i ;
        }

        vector<pair<int , int>> intervals ;

        for (int c = 0 ; c < 26 ; c++)
        {
            if (right[c] == -1) continue ;

            int L = left[c] ;
            int R = right[c] ;

            bool valid = true ;

            for (int i = L ; i <= R ; i++)
            {
                int ch = s[i] - 'a' ;

                if (left[ch] < L)
                {
                    valid = false ;
                    break ;
                }

                R = max(R , right[ch]) ;
            }

            if (valid)
            {
                intervals.push_back({L,R}) ;
            }
        }

        sort(intervals.begin() , intervals.end() , [](auto &a , auto &b)
        {
            return a.second < b.second ;
        });

        vector<string> ans ;

        int lastEnd = -1 ;

        for (auto &[L,R] : intervals)
        {
            if (L > lastEnd)
            {
                ans.push_back(s.substr(L , R-L+1)) ;
                lastEnd = R ;
            }
        }

        return ans ;
    }
};