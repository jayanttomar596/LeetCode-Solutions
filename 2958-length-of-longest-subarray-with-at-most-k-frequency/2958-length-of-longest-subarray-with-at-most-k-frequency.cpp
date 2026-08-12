class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int> mp ;
        int ans = 1 ;
        int n = nums.size() ;

        int l = 0 ;

        int i = 0 ;

        while(i < n)
        {
            mp[nums[i]]++ ;

            if (mp[nums[i]] > k)
            {
                while(mp[nums[i]] > k)
                {
                    mp[nums[l]]-- ;
                    l++ ;
                }
            }
            ans = max(ans , i-l+1) ;
            i++;
        }

        return ans ;
    }
};