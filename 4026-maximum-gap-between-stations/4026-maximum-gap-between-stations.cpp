class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> first(n) ;
        vector<int> last(n) ;

        int j = 0 ;

        for (int i = 0 ; i < n ; i++) 
        {
            while (station[j] != skill[i])
            {
                j++;
            }

            first[i] = j ;
            j++ ; 
        }

        j = m - 1 ;

        for (int i = n - 1; i >= 0; i--) 
        {
            while (station[j] != skill[i]) 
            {
                j-- ;
            }

            last[i] = j ;
            j-- ;
        }

        int answer = 0 ;

        for (int i = 1 ; i < n ; i++) 
        {
            answer = max(answer, last[i] - first[i - 1]) ;
        }

        return answer ;
    }
};