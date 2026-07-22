class DSU
{
    vector<int> rank , parent , size ;
    public :

    DSU(int n)
    {
        rank.resize(n+1,0) ;
        parent.resize(n+1) ;
        size.resize(n+1) ;

        for (int i = 0 ; i <= n ; i++)
        {
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node ;
        return parent[node] = find(parent[node]) ;
    }

    void unionbyrank(int u , int v)
    {
        int up = find(u) ;
        int vp = find(v) ;

        if (up == vp) return ;

        if (rank[up] < rank[vp])
        {
            parent[up] = vp ;
        }
        else if (rank[vp] < rank[up])
        {
            parent[vp] = up ;
        } 
        else
        {
            parent[vp] = up ;
            rank[up]++ ;
        }
    }


    void unionbysize(int u , int v)
    {
        int up = find(u) ;
        int vp = find(v) ;

        if (up == vp) return ;

        if (size[up] < size[vp])
        {
            parent[up] = vp ;
            size[vp] += size[up] ;
        }
        else
        {
            parent[vp] = up ;
            size[up] += size[vp] ;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;

        DSU ds(n) ;

        unordered_map<string , int> mp ;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 1 ; j < accounts[i].size() ; j++)
            {
                string mail = accounts[i][j] ;

                if (mp.find(mail) == mp.end())
                {
                    mp[mail] = i ;
                }
                else
                {
                    ds.unionbysize(i , mp[mail]) ;
                }
            }
        }


        vector<string> merge[n] ;
        for (auto it : mp)
        {
            string mail = it.first ;
            int node = ds.find(it.second) ;
            merge[node].push_back(mail) ;
        }


        vector<vector<string>> ans ;
        for (int i = 0 ; i < n ; i++)
        {
            if (merge[i].empty()) continue ;

            sort(merge[i].begin() , merge[i].end()) ;

            vector<string> temp ;
            temp.push_back(accounts[i][0]) ;

            for (auto &mail : merge[i])
            {
                temp.push_back(mail) ;
            }

            ans.push_back(temp) ;
        }

        sort(ans.begin() , ans.end()) ;
        return ans ;
    }
};