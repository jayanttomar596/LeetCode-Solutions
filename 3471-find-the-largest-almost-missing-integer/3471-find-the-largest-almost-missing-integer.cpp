class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int , int> mp ;
        int n = nums.size() ;
        for (int &i : nums)
        {
            mp[i]++ ;
        }

        if (k == 1)
        {
            int ans = -1 ;

            for (int i = 0 ; i < n ; i++)
            {
                if (mp[nums[i]] == 1)
                {
                    ans = max(ans , nums[i]) ;
                }
            }

            return ans ;
        }
        else if (k == n)
        {
            return *max_element(nums.begin() , nums.end()) ;
        }
        else 
        {
            int op1 = -1 , op2 = -1 ;
            if (mp[nums[0]] == 1) op1 = nums[0] ;
            if (mp[nums[n-1]] == 1) op2 = nums[nums.size()-1] ;

            return max(op1 , op2) ;
        }
    }
};