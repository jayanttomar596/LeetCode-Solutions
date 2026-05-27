class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int , pair<bool , bool>> mp; 

        for (char &ch : word)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                if (mp[ch-'a'].second == true)
                {
                    mp[ch-'a'].first = false ;
                }
                else
                {
                    mp[ch - 'a'].first = true ;
                }
            }
            else
            {                                                                                                                                                                  mp[ch-'A'].second = true ;
            }
        }
        int cnt = 0 ;

        for (auto &i : mp)
        {
            if (i.second.first && i.second.second)
            {
                cnt++ ;
            }
        }

        return cnt ;
    }
};