class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size() ;

        int min_i = min_element(nums.begin() , nums.end()) - nums.begin();
        int max_i = max_element(nums.begin() , nums.end()) - nums.begin();

        int l = min(max_i , min_i) ;
        int r = max(max_i , min_i) ;

        return min({r+1 , n-l , l+1+n-r}) ;
    }
};