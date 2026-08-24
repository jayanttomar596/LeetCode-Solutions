class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin() , nums.end()) ;

        vector<vector<int>> ans ;
        int n = nums.size() ;
        int start = lower ;
        int last = nums[0] ;

        for (int i = 0 ; i < n && nums[i] <= upper ; i++)
        {
            if (nums[i] > start)
            {
                ans.push_back({start , nums[i]-1}) ;
                start = nums[i] + 1 ;
            }
            else if (start == nums[i]) start++ ;
        } 

        if (start <= upper)
        {
            ans.push_back({start , upper}) ;
        }

        return ans ;
    }
};