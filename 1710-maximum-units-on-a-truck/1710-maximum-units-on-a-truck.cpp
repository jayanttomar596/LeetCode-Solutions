class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , cmp) ;

        // descending order on the basis of no of units per box
        int curr = 0 ;
        int val = 0 ;

        int n = boxTypes.size() ;

        for (int i = 0 ; i < n ; i++)
        {
            if (curr + boxTypes[i][0] <= truckSize)
            {
                curr += boxTypes[i][0] ;
                val += (boxTypes[i][1] * boxTypes[i][0]) ;
            }
            else
            {
                int remain = truckSize - curr ;
                val += (boxTypes[i][1] * remain) ;
                break ;
            }
        }

        return val ;
    }
};