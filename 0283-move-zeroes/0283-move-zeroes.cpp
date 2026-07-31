class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0 ;
        int n = nums.size() ;
        int cnt = 0;

        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i] ;
            }
            else
            {
                cnt++ ;
            }
        }

        while(j < n)
        {
            nums[j++] = 0 ;
        }
    }
};