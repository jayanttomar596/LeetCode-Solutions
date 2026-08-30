class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN ;
        int max_i = 0 ;
        int mini = INT_MAX ;
        int min_i = 0 ;

        int n = nums.size() ;

        for (int i = 0 ; i < n ; i++)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i] ;
                max_i = i ;
            }

            if (nums[i] < mini)
            {
                mini = nums[i] ;
                min_i = i ;
            }
        }


        int l = min(max_i , min_i) ;
        int r = max(max_i , min_i) ;

        int op1 = l+1 + (n-r) ;
        int op2 = r+1 ;
        int op3 = n-l ;

        return min({op1 , op2 , op3}) ;
    }
};