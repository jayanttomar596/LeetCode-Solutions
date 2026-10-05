class Solution {
    bool isValid(vector<int>& cnt)
    {
        for (int c = 1 ; c <= 500 ; c++)
        {
            if (cnt[c] == 0) continue ;

            for (int a = 1 ; a <= c/2 ; a++)
            {
                int b = c - a ;

                if (a != b)
                {
                    if (cnt[a] > 0 && cnt[b] > 0) return false ;
                }
                else
                {
                    if (cnt[a] >= 2) return false ;
                }
            }
        }

        return true ;
    }
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> cnt(501 , 0) ;
        int l = 0 , ans = 0 ;

        for (int r = 0 ; r < n ; r++)
        {
            cnt[nums[r]]++ ;

            while(!isValid(cnt))
            {
                cnt[nums[l]]-- ;
                l++ ;
            }
            ans = max(ans , r-l+1) ;
        }
        return ans ;
    }
};