class Solution {
public:
    bool consecutiveSetBits(int n) {
        int cnt = 0 ;
        int prev = 0;

        while(n)
            {
                int curr = n&1 ;

                if (curr && prev) cnt++ ;

                prev = curr ;
                n >>= 1 ;
            }

        return cnt == 1 ;
    }
};