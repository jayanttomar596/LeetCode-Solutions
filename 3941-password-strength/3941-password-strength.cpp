class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st ;
        for (char ch : password) 
            {
                st.insert(ch) ;
            }
        int ans = 0 ;

        for (auto i : st)
            {
                if (i >= 'a' && i <= 'z') ans++ ;
                if (i >= 'A' && i <= 'Z') ans += 2 ;
                if (i >= '0' && i <= '9') ans += 3 ;
                if (i == '!' || i == '@' || i == '#' || i == '$') ans += 5 ;
            }

        return ans ;
    }
};