class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<bool , bool>> v(26 , {false , false});

        for (char &ch : word)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                v[ch-'a'].first = true ;
            }
            else
            {
                v[ch - 'A'].second = true ;
            }
        }

        int cnt = 0 ;
        for (int i = 0 ; i < 26 ; i++)
        {
            if (v[i].first && v[i].second) cnt++ ; 
        }

        return cnt ;
    }
};