class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0 ;
        int non0 = false ;

        for (int &i : nums)
        {
            x ^= i ;
            if (i != 0) non0 = true ;
        }

        if (x != 0) return nums.size() ;
        else if (!non0) return 0 ;

        return nums.size() - 1 ;
    }
};