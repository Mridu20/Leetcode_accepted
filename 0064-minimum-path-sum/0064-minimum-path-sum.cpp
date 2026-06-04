class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        int dp[n][m];

        dp[0][0] = a[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0)continue;
                int lft = j-1;
                int up = i-1;

                dp[i][j] = a[i][j];
                if(i == 0){
                    dp[i][j] += dp[i][lft];
                }
                else if(j == 0){
                    dp[i][j] += dp[up][j];
                }
                else{
                    dp[i][j] += min(dp[up][j], dp[i][lft]);
                }
            }
        }

        return dp[n-1][m-1];
    }
};