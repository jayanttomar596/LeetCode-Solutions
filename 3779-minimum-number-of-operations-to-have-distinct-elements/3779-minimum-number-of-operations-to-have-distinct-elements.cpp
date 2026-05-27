class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int , int> freq ;

        for (int x : nums)
        {
            freq[x]++ ;
        }

        int dup = 0 ;

        for (auto &p : freq)
        {
            if (p.second > 1)
            {
                dup++ ;
            }
        }

        if (dup == 0) return 0 ;

        int op = 0 ;
        int n = nums.size() ;

        for (int i = 0 ; i < n ; i += 3)
        {
            for (int j = i ; j < min(i+3 , n) ; j++)
            {
                int val = nums[j] ;

                if (freq[val] > 1 && freq[val] - 1 == 1)
                    dup-- ;
                freq[val]-- ;
            }

            op++ ;
            if (dup == 0) return op ;
        }

        return op ;
    }
};