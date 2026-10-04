class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int, int>, int> mp;
        int ans = 0;
        int best = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                ans++;
            else {
                int x = min(nums[i], nums[i - 1]);
                int y = max(nums[i], nums[i - 1]);

                mp[{x, y}]++;
                best = max(best, mp[{x, y}]);
            }
        }
        ans += best;
        return ans;
    }
};