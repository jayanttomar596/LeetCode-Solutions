class Solution {
    bool isValid(const string& s)
    {
        int cnt = 0 ;
        for (char c : s)
        {
            if (c == '(') cnt++ ;
            else if (c == ')') cnt-- ;

            if (cnt < 0) return false ;
        }

        return cnt == 0 ;
    }

    void dfs(string s , int start , int l , int r , vector<string>& result)
    {
        if (l == 0 && r == 0)
        {
            if (isValid(s))
            {
                result.push_back(s) ;
            }

            return  ;
        }

        for (int i = start ; i < s.length() ; i++)
        {
            if (i != start && s[i] == s[i-1]) continue ;

            if (s[i] == '(' || s[i] == ')')
            {
                string next_str = s.substr(0 , i) + s.substr(i+1) ;

                if (r > 0 && s[i] == ')') dfs(next_str , i , l , r-1 , result) ;
                else if (l > 0 && s[i] == '(') dfs(next_str , i , l-1 , r , result) ;
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0 , r = 0 ;

        for (char &c : s)
        {
            if (c == '(') l++ ;
            else if (c == ')')
            {
                if (l > 0) l-- ;
                else r++ ;
            }
        }

        vector<string> result ;
        dfs(s , 0 , l , r , result) ;
        return result ;
    }
};