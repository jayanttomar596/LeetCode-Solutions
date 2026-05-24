class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size() ;
        unordered_map<int, int> mp ;
        for (int &x : nums)
            {
                mp[x]++ ;
            }

        vector<int> num ;
        for (auto x : mp)
            {
                int time = min(k , x.second) ;
                for (int i = 0 ; i < time ; i++)
                    {
                        num.push_back(x.first) ;
                    }
            }

        sort(num.begin() , num.end()) ;

        return num ;
    }
};