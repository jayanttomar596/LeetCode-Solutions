class Solution {
    bool check(long long sum , int x)
    {
        if (sum%10 != x) return false ;

        while(sum)
        {
            if (sum/10 == 0)
            {
                if (sum != x) return false ;
            }

            sum /= 10 ;
        }

        return true ;
    }
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int cnt = 0 ;
        int n = nums.size() ;

        for (int i = 0 ; i < n ; i++)
        {
            long long sum = 0 ;
            for (int j = i ; j < n ; j++)
            {
                sum += nums[j] ;
                if (check(sum , x)) cnt++ ;
            }
        }

        return cnt ;
    }
};