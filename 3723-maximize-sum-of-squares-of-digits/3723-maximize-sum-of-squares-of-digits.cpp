class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num*9 < sum) return "" ;

        string ans ;

        int nine = sum/9 ;
        int left = sum%9 ;

        for (int i = 0 ; i < nine ; i++)
        {
            ans.push_back('9') ;
            num-- ;
        }
        if (left != 0)
        {
            char ch = '0' + left ;
            ans.push_back(ch) ;
            num-- ;
        }
        

        while(num > 0)
        {
            num-- ;
            ans.push_back('0') ;
        }

        return ans ;
    }
};