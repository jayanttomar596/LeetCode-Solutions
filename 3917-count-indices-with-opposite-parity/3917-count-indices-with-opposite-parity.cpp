class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size() ;
        int odd = 0 , even = 0 ;

        for (int i = n-1 ; i >= 0 ; i--)
        {
            if (nums[i]&1) //odd
            {
                nums[i] = even ;
                odd++ ;
            }
            else //even
            {
                nums[i] = odd ;
                even++ ;
            }
        }

        return nums ;
    }
};