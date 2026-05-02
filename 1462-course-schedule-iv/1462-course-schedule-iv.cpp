class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> dist(numCourses , vector<bool>(numCourses , false)) ;

        for (auto &i : prerequisites)
        {
            dist[i[0]][i[1]] = true ;
        }


        for (int k = 0 ; k < numCourses ; k++)
        {
            for (int i = 0 ; i < numCourses ; i++)
            {
                for (int j = 0 ; j < numCourses ; j++)
                {
                    if (dist[i][k] == false || dist[k][j] == false)
                        continue ;
                    
                    if (dist[i][j] == false)
                    {
                        dist[i][j] = true ;
                    }
                }
            }
        }


        // now queries
        vector<bool> ans;
        for (auto &i : queries)
        {
            ans.push_back(dist[i[0]][i[1]]) ;
        }
        
        return ans ;
    }
};