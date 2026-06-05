class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0] = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0)continue;
                int lft = j-1;
                int up = i-1;

                if(i == 0)dp[i][j] = dp[i][lft];
                else if(j == 0)dp[i][j] = dp[up][j];
                else dp[i][j] = dp[up][j] + dp[i][lft];
            }
        }

        return dp[m-1][n-1];
    }
};