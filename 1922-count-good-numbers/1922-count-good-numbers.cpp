class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }

            a = (a * a) % MOD;
            b >>= 1;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long evenWays = power(5, evenPos);
        long long oddWays = power(4, oddPos);

        return (evenWays * oddWays) % MOD;
    }
};