class Solution {
public:
    int minInsertions(string s) {
        stack<char> st ;
        int ans = 0 ;
        int cnt = 0 ;

        for (char &ch : s)
        {
            if (ch == '(')
            {
                if (cnt == 1)
                {
                    ans++ ;
                    cnt = 0 ;

                    if (!st.empty())
                    {
                        st.pop() ;
                    }
                    else
                    {
                        ans++ ;
                    }
                }

                st.push(ch) ;
            }
            else
            {
                if (cnt == 0)
                {
                    cnt++ ;
                }
                else
                {
                    if (!st.empty())
                    {
                        st.pop() ;
                    }
                    else
                    {
                        ans++ ;
                    }
                    cnt = 0 ;
                }
            }
        }

        if (cnt == 1)
        {
            ans++ ;
            if (!st.empty())
            {
                st.pop() ;
            }
            else
            {
                ans++ ;
            }
        }

        ans += (2 * st.size()) ;

        return ans ;
    }
};