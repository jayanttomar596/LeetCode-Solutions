class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans = 0 ;
        string s = to_string(n) ;

        for (char &ch : s)
            {
                ans += (ch - '0') ;
            }

        return ans ;
    }
};