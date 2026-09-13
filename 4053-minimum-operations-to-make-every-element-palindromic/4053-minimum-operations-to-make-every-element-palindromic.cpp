vector<long long> pal[2] ;

int init = []()
{
    const long long LIMIT = 1e9 ;

    for (int half = 1 ; half < 100000 ; half++)
    {
        string s = to_string(half) ;

        string rev = s ;
        reverse(rev.begin() , rev.end()) ;

        string oddStr = s.substr(0,s.size()-1) + rev ;
        long long oddPal = stoll(oddStr) ;

        string evenStr = s + rev ;
        long long evenPal = stoll(evenStr) ;

        if (oddPal < LIMIT) pal[oddPal%2].push_back(oddPal) ;

        if (evenPal < LIMIT) pal[evenPal%2].push_back(evenPal) ;
    }

    sort(pal[0].begin() , pal[0].end()) ;
    sort(pal[1].begin() , pal[1].end()) ;

    return 0 ;
}();

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long ans = 0 ;

        for (long long x : nums)
        {
            vector<long long>& candidates = pal[x%2] ;

            int pos = lower_bound(candidates.begin() , candidates.end() , x) - candidates.begin() ;

            long long best = LLONG_MAX ;

            if (pos < candidates.size())
            {
                best = min(best , abs(x - candidates[pos])) ;
            }

            if (pos > 0)
            {
                best = min(best , abs(x - candidates[pos-1])) ;
            }

            ans += best/2 ;
        }

        return ans ;
    }
};