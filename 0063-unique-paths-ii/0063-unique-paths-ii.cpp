class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int dp[n][m];

        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0)continue;

                int up = i-1;
                int lft = j-1;

                if(i == 0){
                    dp[i][j] = dp[i][lft];
                }
                else if(j == 0){
                    dp[i][j] = dp[up][j];
                }
                else{
                    dp[i][j] = dp[up][j] + dp[i][lft];
                }

            }
        }

        return dp[n-1][m-1];

    }
};