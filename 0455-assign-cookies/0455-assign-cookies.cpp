class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end()) ;
        sort(s.begin() , s.end()) ;
        int count = 0 ;

        int g1 = 0 ;
        int s1 = 0 ;

        while(g1 < g.size() && s1 < s.size())
        {
            if (g[g1] <= s[s1])
            {
                count++ ;
                g1++ ;
                s1++ ;
            }
            else
            {
                s1++ ;
            }
        }

        return count ;
    }
};