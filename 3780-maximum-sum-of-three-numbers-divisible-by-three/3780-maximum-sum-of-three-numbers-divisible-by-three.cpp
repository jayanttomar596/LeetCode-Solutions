class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> rem1 ;
        vector<int> rem2 ;
        vector<int> rem3 ;

        for (int &i : nums)
            {
                if (i%3 == 0) rem3.push_back(i) ;
                else if (i%3 == 1) rem1.push_back(i) ;
                else rem2.push_back(i) ;
            }

        sort(rem1.begin() , rem1.end()) ;
        sort(rem2.begin() , rem2.end()) ;
        sort(rem3.begin() , rem3.end()) ;


        int n1 = rem1.size() ;
        int n2 = rem2.size() ;
        int n3 = rem3.size() ;

        int op1 = 0 , op2 = 0 , op3 = 0 , op4 = 0 ;
        if (n1 >= 3)
        {
            op1 = rem1[n1-1] + rem1[n1-2] + rem1[n1-3] ;
        }
        if (n2 >= 3)
        {
            op2 = rem2[n2-1] + rem2[n2-2] + rem2[n2-3] ;
        }
        if (n3 >= 3)
        {
            op3 = rem3[n3-1] + rem3[n3-2] + rem3[n3-3] ;
        }

        if (n1 >= 1 && n2 >= 1 && n3 >= 1)
        {
            op4 = rem1[n1-1] + rem2[n2-1] + rem3[n3-1] ; 
        }

        return max({op1 , op2 , op3 , op4}) ;
    }
};