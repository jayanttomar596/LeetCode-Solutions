class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cnt = 0 ;
        int ans = 0 ;

        for (int &i : gain)
        {
            cnt += i ;
            ans = max(ans , cnt) ;
        }
        return ans ;
    }
};