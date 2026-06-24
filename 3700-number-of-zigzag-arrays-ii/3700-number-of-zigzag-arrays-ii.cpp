class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();

        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long cur = A[i][k];

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // up[x] -> down[y] for y > x
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++) {
                T[x][m + y] = 1;
            }
        }

        // down[x] -> up[y] for y < x
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++) {
                T[m + x][y] = 1;
            }
        }

        Matrix P = power(T, n - 1);

        vector<long long> start(S, 1);

        long long ans = 0;

        for (int j = 0; j < S; j++) {
            long long ways = 0;

            for (int i = 0; i < S; i++) {
                ways = (ways + start[i] * P[i][j]) % MOD;
            }

            ans = (ans + ways) % MOD;
        }

        return (int)ans;
    }
};