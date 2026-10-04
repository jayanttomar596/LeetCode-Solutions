class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> prefix(n + 1);

        for (int i = 0; i < n; i++) 
        {
            prefix[i + 1] = (prefix[i] + nums[i]) % k;

            if (prefix[i + 1] < 0)
                prefix[i + 1] += k;
        }

        vector<int> first(k, -1);

        vector<int> order;

        for (int i = 0; i <= n; i++) 
        {

            int r = prefix[i];

            if (first[r] == -1) 
            {
                first[r] = i;
                order.push_back(r);
            }
        }

        vector<int> best(k, n + 1);

        for (int r = 0; r < k; r++) 
        {
            if (first[r] != -1) {
                best[r] = first[r];
            }
        }

        vector<int> ptr(k, 0);

        int answer = 0;

        for (int i = 0; i < n; i++) 
        {
            int a = (2LL * nums[i]) % k;

            if (a < 0)
                a += k;

            while (ptr[a] < (int)order.size() &&
                   first[order[ptr[a]]] <= i) 
            {

                int q = order[ptr[a]];

                int target = (q + a) % k;

                best[target] = min(best[target], first[q]);

                ptr[a]++;
            }

            int rightRemainder = prefix[i + 1];

            if (best[rightRemainder] <= i) 
            {
                int length = (i + 1) - best[rightRemainder];
                answer = max(answer, length);
            }
        }

        return answer;
    }
};