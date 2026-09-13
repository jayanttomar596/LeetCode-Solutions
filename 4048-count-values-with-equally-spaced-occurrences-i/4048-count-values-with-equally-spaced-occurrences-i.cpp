class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , int> freq ;
        for (int &i : nums)
            {
                freq[i]++ ;
            }

        vector<int> pos ;
        for (auto &i : freq)
            {
                if (i.second == 3)pos.push_back(i.first);
            }
        int ans = 0 ;

        // we got the possibilities
        for (int &num : pos)
            {
                int pos1 = -1 , pos2 = -1 , pos3 = -1 ;
                for (int i = 0 ; i < n ; i++)
                {
                    if (nums[i] == num)
                    {
                        if (pos1 == -1) pos1 = i ;
                        else if (pos2 == -1) pos2 = i ;
                        else pos3 = i ;
                    }
                }
                if (pos2 - pos1 == pos3 - pos2) ans++ ;
            }

        return ans ;
    }
};