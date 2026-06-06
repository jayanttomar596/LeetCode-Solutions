class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long bulbs = (brightness + 2)/3 ;

        sort(intervals.begin() , intervals.end()) ;

        long long activeTime = 0 ;

        long long L = intervals[0][0] ;
        long long R = intervals[0][1] ;

        for (int i = 1 ; i < intervals.size() ; i++)
            {
                long long l = intervals[i][0] ;
                long long r = intervals[i][1] ;

                if(l <= R+1)
                {
                    R = max(R , r) ;
                }
                else
                {
                    activeTime += R-L+1 ;
                    L = l ;
                    R = r ;
                }
            }

        activeTime += R-L+1 ;

        return bulbs * activeTime ;
    }
};