class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int ptr = 0 ; 
        int n = nums.size() ;
        int temp = 0 ;
        int cnt = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            if (i == 0 || nums[i] == nums[i-1])
            {
                temp++ ;
                if (temp <= k)
                {
                    nums[ptr++] = nums[i] ;
                }
                else
                {
                    cnt++ ;
                }
            }
            else
            {
                temp = 1 ;
                if (temp <= k)
                {
                    nums[ptr++] = nums[i] ;
                }
                else
                {
                    cnt++ ;
                }
            }
        }

        for (int i = 0 ; i < cnt ; i++)
        {
            nums.pop_back() ;
        }

        return nums ;
    }
};