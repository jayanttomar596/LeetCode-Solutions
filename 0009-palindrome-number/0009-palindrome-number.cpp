class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x) ;
        string s = to_string(x) ;
        reverse(s.begin() , s.end()) ;

        if (s == y) return true ;
        else return false ;
    }
};