class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i = 0 ;

        for (auto &n : nums)
        {
            if (i < k || n != nums[i-k])
                nums[i++] = n ;
        }

        while(nums.size() > i) nums.pop_back() ;

        return nums ;
    }
};