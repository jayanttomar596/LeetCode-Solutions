class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26,0) ;

        for (char &ch : s)
        {
            mp[ch-'a']++ ;
        }

        for (char &ch : t)
        {
            mp[ch-'a']-- ;
        }

        int ans = 0 ;
        for (int &i : mp)
        {
            ans += abs(i) ;
        }

        return ans ;
    }
};