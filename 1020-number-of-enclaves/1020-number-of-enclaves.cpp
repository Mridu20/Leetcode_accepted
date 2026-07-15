class Solution {
public:
    void bfs(vector<vector<int>>& grid, int i, int j,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m &&
                   grid[nx][ny]==1 && !vis[nx][ny]) {

                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int i=0;i<n;i++) {
            if(grid[i][0]==1 && !vis[i][0])
                bfs(grid,i,0,vis);

            if(grid[i][m-1]==1 && !vis[i][m-1])
                bfs(grid,i,m-1,vis);
        }

        for(int j=0;j<m;j++) {
            if(grid[0][j]==1 && !vis[0][j])
                bfs(grid,0,j,vis);

            if(grid[n-1][j]==1 && !vis[n-1][j])
                bfs(grid,n-1,j,vis);
        }

        int ans = 0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1 && !vis[i][j])
                    ans++;
            }
        }

        return ans;
    }
};