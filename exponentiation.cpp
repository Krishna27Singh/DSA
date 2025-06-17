//calculate exponent in logb time complexity

int MOD = 1000000007;

long long bin_expo(long long a, long long b)
    {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }