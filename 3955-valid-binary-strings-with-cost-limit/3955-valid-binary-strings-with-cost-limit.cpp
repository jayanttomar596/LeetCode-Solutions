class Solution {
    void solve(int n , int k , string temp , vector<string>& ans , bool check)
    {
        if (temp.size() == n && k >= 0)
        {
            ans.push_back(temp) ;
            return ;
        }
        if (k < 0 || temp.size() == n)
        {
            return ;
        }

        // insert 0 
        temp.push_back('0') ;
        solve(n , k , temp , ans , false) ;
        temp.pop_back() ;

        // insert 1 
        if (!check)
        {
            temp.push_back('1') ;
            k -= (temp.size()-1) ;
            solve(n , k , temp , ans , true) ;
            temp.pop_back() ;
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans ;
        solve(n , k , "" , ans , false) ;

        return ans ;
    }
};