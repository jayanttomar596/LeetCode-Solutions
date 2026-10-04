class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0 , maxi = 0 ;

        for (char &ch : s)
        {
            if (ch == '(')
            {
                mini++ ;
                maxi++ ;
            }
            else if (ch == ')')
            {
                mini-- ;
                maxi-- ;
            }
            else
            {
                mini-- ;
                maxi++ ;
            }

            if (maxi < 0) return false ;

            mini = max(0 ,mini) ;
        }

        return mini == 0 ;
    }
};