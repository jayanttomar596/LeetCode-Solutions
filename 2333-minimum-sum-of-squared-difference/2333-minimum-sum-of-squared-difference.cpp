class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0 ;
        map<int , int> mp ;

        for (int i = 0 ; i < nums1.size() ; i++)
        {
            mp[abs(nums1[i] - nums2[i])]++ ;
        }

        // we got the map 
        int op = k1+k2 ;

        for (auto it = mp.rbegin() ; it != mp.rend() ; it++)
        {
            if (op <= 0) break ;
            int diff = it->first ;
            if (diff == 0) break ;
            long long reduce_count = min((long long)mp[diff], (long long)op);
    
            // Apply them in bulk!
            mp[diff] -= reduce_count;
            mp[diff - 1] += reduce_count;
            op -= reduce_count;
        }

        for (auto &it : mp)
        {
            long long sq = 1LL * it.first * it.first ;
            sq *= it.second ;
            ans += sq ;
        }

        return ans ;
    }
};