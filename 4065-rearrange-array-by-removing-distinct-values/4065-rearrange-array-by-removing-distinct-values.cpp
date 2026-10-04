class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int , int> mp;
        for (int &i : nums)
            {
                mp[i]++ ;
            }
        vector<int> ans ;

        while(ans.size() != nums.size())
        {
            for (auto &it : mp)
                {
                    if (it.second > 0)
                    {
                        ans.push_back(it.first) ;
                        it.second-- ;
                    }
                }
        }

        return ans ;
    }
};