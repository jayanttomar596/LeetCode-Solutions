class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0 ;
        int cnt = 0 ;

        for (auto s : events)
            {
                if (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || s == "6")
                {
                    score += (s[0] - '0') ;
                }
                else if (s == "W") cnt++ ;
                else if (s == "WD") score++ ;
                else if (s == "NB") score++ ;

                if (cnt == 10) break ;
            }

        return {score , cnt} ;
    }
};