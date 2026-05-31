class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size() ;

        vector<int> freq(1501 , 0) ;
        int cheapest = INT_MAX ;

        for (auto &item : items)
            {
                freq[item[0]]++ ;
                cheapest = min(cheapest , item[1]) ;
            }

        vector<int> multiples(1501 , 0) ;

        for (int d = 1 ; d <= 1500 ; d++)
            {
                for (int m = d ; m <= 1500 ; m += d)
                    {
                        multiples[d] += freq[m] ;
                    }
            }


        vector<int> dp(budget + 1 , 0) ;

        for (auto &item : items)
            {
                int factor = item[0] ;
                int price = item[1] ;

                int gain = multiples[factor] ;

                for (int b = budget ; b >= price ; b--)
                    {
                        dp[b] = max(dp[b] , dp[b-price] + gain) ;
                    }
            }

        int ans = 0 ;

        for (int used = 0 ; used <= budget ; used++)
            {
                int remain = budget - used ;
                ans = max(ans , dp[used] + remain/cheapest) ;
            }

        return ans ;
    }
};