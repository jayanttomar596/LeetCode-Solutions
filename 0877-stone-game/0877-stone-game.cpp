class Solution {
    void solve(vector<int>& piles , int num , int l , int r , bool turn , bool &ans)
    {
        if (l >= r)
        {
            ans = num > 0 ;
            return ;
        }

        if (turn) //alice choice 
        {
            if (piles[l] > piles[r])
            {
                solve(piles , num + piles[l] , l+1 , r , !turn , ans) ;
            }
            else
            {
                solve(piles , num + piles[r] , l , r-1 , !turn , ans) ;
            }
        }
        else //bob choice 
        {
            if (piles[l] > piles[r])
            {
                solve(piles , num - piles[l] , l+1 , r , !turn , ans) ;
            }
            else
            {
                solve(piles , num - piles[r] , l , r-1 , !turn , ans) ;
            }
        }

    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size() ;
        bool ans = false ;
        solve(piles , 0 , 0 , n-1 , true , ans) ;
        return true ;
    }
};