class Solution {
    vector<int> dp;
    set<int> unvisited;

    bool solve(string &s, int minJump, int maxJump, int index) {
        if (index == s.size() - 1)
            return true;

        if (dp[index] != -1)
            return dp[index];

        int left = index + minJump;
        int right = min(index + maxJump, (int)s.size() - 1);

        auto it = unvisited.lower_bound(left);

        while (it != unvisited.end() && *it <= right) {
            int next = *it;

            // Erase BEFORE recursion.
            unvisited.erase(it);

            if (solve(s, minJump, maxJump, next))
                return dp[index] = 1;

            // Recursive call may have modified the set,
            // so NEVER use 'it' again.
            it = unvisited.lower_bound(next + 1);
        }

        return dp[index] = 0;
    }

public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        dp.assign(n, -1);
        unvisited.clear();

        for (int i = 1; i < n; i++) {
            if (s[i] == '0')
                unvisited.insert(i);
        }

        return solve(s, minJump, maxJump, 0);
    }
};