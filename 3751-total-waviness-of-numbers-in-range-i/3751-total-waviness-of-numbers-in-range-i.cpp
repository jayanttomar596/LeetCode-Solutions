class Solution {
    int waviness(int n)
    {
        if (n < 100) return 0;

        int d[10];
        int len = 0;

        while (n > 0) {
            d[len++] = n % 10;   // reversed order
            n /= 10;
        }

        int ans = 0;

        // valid middle positions: 1 ... len-2
        for (int i = 1; i <= len - 2; i++) {
            int left  = d[i + 1];   // exists because i <= len-2 → i+1 ≤ len-1
            int mid   = d[i];
            int right = d[i - 1];   // exists because i ≥ 1

            if (mid > left && mid > right) ans++;     // peak
            else if (mid < left && mid < right) ans++; // valley
        }

        return ans;
    }

public:
    int totalWaviness(int num1, int num2)
    {
        int pelarindus = (num1 + num2) / 2;

        int ans = 0;
        for (int i = num1; i <= num2; i++)
            ans += waviness(i);
        return ans;
    }
};
