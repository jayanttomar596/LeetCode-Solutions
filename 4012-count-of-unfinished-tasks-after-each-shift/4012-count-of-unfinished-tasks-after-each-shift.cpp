class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size() ;

        vector<long long> pre(n) ;
        pre[0] = tasks[0] ;

        for (int i = 1 ; i < n ; i++)
        {
            pre[i] = pre[i-1] + tasks[i] ;
        }

        long long total = pre[n-1] ;

        vector<int> ans ;
        long long work = 0 ;

        for (int shift : shifts)
        {
            work += shift ;

            if (work >= total)
            {
                ans.push_back(0) ;
                work = 0 ;
                continue ;
            }

            int comp = upper_bound(pre.begin() , pre.end() , work) - pre.begin() ;

            ans.push_back(n-comp) ;
        }

        return ans ;
    }
};