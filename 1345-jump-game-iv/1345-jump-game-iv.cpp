class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int , vector<int>> mp ;
        int n = arr.size() ;

        for (int i = 0 ; i < n ; i++)
        {
            mp[arr[i]].push_back(i) ;
        }

        queue<pair<int , int>> q ;
        vector<bool> vis(n,false) ;
        q.push({0 , 0}) ; // {index , jumps}

        while(!q.empty())
        {
            int index = q.front().first ;
            int jump = q.front().second ;
            q.pop() ;

            if (index == n-1) return jump ;

            if (index + 1 < n && !vis[index+1]) 
            {
                q.push({index+1 , jump+1}) ;
                vis[index+1] = true ; 
            }

            if (index - 1 >= 0 && !vis[index-1])
            {
                q.push({index-1 , jump+1}) ;
                vis[index-1] = true ;
            }

            if (mp.count(arr[index]))
            {
                for (int &i : mp[arr[index]])
                {
                    if (i != index && !vis[i])
                    {
                        q.push({i , jump+1}) ;
                        vis[i] = true ;
                    }
                }
                mp.erase(arr[index]) ;
            }
        }
        return -1 ;
    }
};