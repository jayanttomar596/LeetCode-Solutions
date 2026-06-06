class DisjointSet
{
    vector<int> rank , parent , size ;

public :
    DisjointSet(int n)
    {
        rank.resize(n+1 , 0) ;
        parent.resize(n+1) ;
        size.resize(n+1) ;

        for (int i = 0 ; i < n ; i++)
        {
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int findPar(int node)
    {
        if (node == parent[node]) return node ;

        parent[node] = findPar(parent[node]) ;
        return parent[node] ;
    }

    void unionByRank(int u , int v)
    {
        int pu = findPar(u) ;
        int pv = findPar(v) ;

        if (pu == pv) return ;

        if (rank[pu] < rank[pv]) parent[pu] = pv ;
        else if (rank[pv] < rank[pu]) parent[pv] = pu ;
        else 
        {
            parent[pv] = pu ;
            rank[pu]++ ;
        }
    }


    void unionBySize(int u , int v)
    {
        int pu = findPar(u) ;
        int pv = findPar(v) ;

        if (pu == pv) return ;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv ;
            size[pv] += size[pu] ;
        }
        else
        {
            parent[pv] = pu ;
            size[pu] += size[pv] ;
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size() ;

        DisjointSet ds(n) ;

        unordered_map<string , int> mapMailNode ;

        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 1 ; j < accounts[i].size() ; j++)
            {
                string mail = accounts[i][j] ;

                if (mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i ;
                }
                else
                {
                    ds.unionBySize(i , mapMailNode[mail]) ;
                }
            }
        }


        vector<string> mergedMail[n];
        for (auto it : mapMailNode) 
        {
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        // Step 3: Prepare final merged result
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for (auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        // Sort final answer
        sort(ans.begin(), ans.end());
        return ans;
    }
};