class Solution {
    void solve(vector<int>& ans , int num)
    {
        if (num >1e9) return ;
        if (num != 0) ans.push_back(num) ;

        int last = num%10 ;
        if (last == 9)return ;

        solve(ans , num*10 + last+1) ;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v ;
        for (int i = 1 ; i <= 9 ; i++)
        {
            solve(v , i) ;
        }
        vector<int> ans ;

        for (int &i : v)
        {
            if (i >= low && i <= high) ans.push_back(i) ;
        }
        sort(ans.begin() , ans.end()) ;

        return ans ;
    }
};