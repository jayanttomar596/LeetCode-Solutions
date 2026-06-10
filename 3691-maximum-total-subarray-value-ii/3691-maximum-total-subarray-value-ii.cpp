class Solution {
    vector<vector<int>> mx , mn ;
    vector<int> log2Val ;

    long long getValue(int l , int r)
    {
        int len = r-l+1 ;
        int p = log2Val[len] ;

        int maximum = max(mx[p][l] , mx[p][r - (1 << p) + 1]) ;
        int minimum = min(mn[p][l] , mn[p][r - (1 << p) + 1]) ;

        return 1LL*maximum - minimum ;
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size() ;

        log2Val.resize(n+1) ;
        for (int i = 2 ; i <= n ; i++)
        {
            log2Val[i] = log2Val[i/2]+1 ;
        }

        int LOG = log2Val[n] + 1 ;

        mx.assign(LOG , vector<int>(n)) ;
        mn.assign(LOG , vector<int>(n)) ;

        for (int i = 0 ; i < n ; i++)
        {
            mx[0][i] = nums[i] ;
            mn[0][i] = nums[i] ;
        }

        for (int j = 1 ; j < LOG ; j++)
        {
            int len = 1 << j ;

            for (int i = 0 ; i + len <= n ; i++)
            {
                mx[j][i] = max(mx[j-1][i] , 
                mx[j-1][i + (len >> 1)]) ;
                mn[j][i] = min(mn[j-1][i] , 
                mn[j-1][i + (len >> 1)]) ;
            }
        }

        using State = tuple<long long , int , int> ;
        priority_queue<State> pq ;

        for (int l = 0 ; l < n ; l++)
        {
            pq.push({getValue(l , n-1) , l , n-1}) ;
        }

        long long answer = 0 ;

        while(k--)
        {
            auto [value , l , r] = pq.top() ;
            pq.pop();

            answer += value ;

            if (r > l)
            {
                pq.push({getValue(l , r-1) , l , r-1}) ;
            }
        }

        return answer ;
    }
};