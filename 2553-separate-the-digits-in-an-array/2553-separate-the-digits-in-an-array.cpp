class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string ans = "" ;

        for (int n : nums)
        {
            string s = to_string(n) ;
            ans += s ;
        }

        vector<int> v ;
        for (char ch : ans)
        {
            v.push_back(ch - '0') ;
        }

        return v ;
    }
};