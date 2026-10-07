class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = -(1LL << 60);

        long long a = NEG;
        long long b = NEG;
        long long c = NEG;
        long long d = NEG;

        long long ans = NEG;

        for (long long x : nums) {

            long long na = b - x;

            long long nb = max(a + x, x);

            long long nc = max(d - x, a);

            long long nd = max(c + x, b);

            a = na;
            b = nb;
            c = nc;
            d = nd;

            ans = max({ans, a, b, c, d});
        }

        return ans;
    }
};