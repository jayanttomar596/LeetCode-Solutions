class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i = series1.size() - 1 ;
        int j = series2.size() - 1 ;

        long long cur1 = 0 , cur2 = 0;
        vector<vector<int>> ans ;

        while (i >= 0 || j >= 0) 
        {
            if (i >= 0 && j >= 0) 
            {
                if (series1[i][0] == series2[j][0]) 
                {
                    cur1 = series1[i][1];
                    cur2 = series2[j][1];
                    ans.push_back({series1[i][0], (int)(cur1 + cur2)});
                    i--;
                    j--;
                } 
                else if (series1[i][0] > series2[j][0]) 
                {
                    cur1 = series1[i][1];
                    ans.push_back({series1[i][0], (int)(cur1 + cur2)});
                    i--;
                } 
                else 
                {
                    cur2 = series2[j][1];
                    ans.push_back({series2[j][0], (int)(cur1 + cur2)});
                    j--;
                }
            } 
            else if (i >= 0) 
            {
                cur1 = series1[i][1];
                ans.push_back({series1[i][0], (int)(cur1 + cur2)});
                i--;
            } 
            else 
            {
                cur2 = series2[j][1];
                ans.push_back({series2[j][0], (int)(cur1 + cur2)});
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};