class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        const long long NEG = -(1LL << 60);

        // a: no deletion, next sign is +
        // b: no deletion, next sign is -
        // c: one deletion, next sign is +
        // d: one deletion, next sign is -

        long long a = NEG;
        long long b = NEG;
        long long c = NEG;
        long long d = NEG;

        long long ans = NEG;

        for (long long x : nums) {
            // Select x
            // +x -> next sign becomes -
            long long na = b - x;

            // Start a new subarray with x OR
            // select x when next sign was +
            long long nb = max(a + x, x);

            // Delete x when next sign is +
            // OR select x when next sign was -
            long long nc = max(d - x, a);

            // Delete x when next sign is -
            // OR select x when next sign was +
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