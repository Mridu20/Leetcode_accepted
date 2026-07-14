class Solution {
public:
    void bfs(vector<vector<char>>& a, int n, int m, vector<vector<int>>& vis, int i, int j, int delx[], int dely[], vector<pair<int,int>>& rgn){
        rgn.push_back({i, j});

        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newx = x+delx[i];
                int newy = y+dely[i];

                if(newx < n && newx>=0 && newy<m && newy>=0 && !vis[newx][newy] && a[newx][newy] == 'O'){
                    rgn.push_back({newx, newy});
                    q.push({newx, newy});
                    vis[newx][newy] = 1;
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<pair<int, int>> idx;

        for(int i=0; i<n; i++){
            if(a[i][0] == 'O')idx.push_back({i, 0});
            if(a[i][m-1] == 'O')idx.push_back({i, m-1});
        }
        for(int j=0; j<m; j++){
            if(a[0][j] == 'O')idx.push_back({0, j});
            if(a[n-1][j] == 'O')idx.push_back({n-1, j});
        }

        int delx[] = {+1, 0, -1, 0};
        int dely[] = {0, +1, 0, -1};

        vector<pair<int,int>> rgn;

        for(auto it: idx){
            int x = it.first;
            int y = it.second;

            if(!vis[x][y]) bfs(a, n, m, vis, x, y, delx, dely, rgn);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                a[i][j] = 'X';
            }
        }

        for(auto it: rgn){
            int x = it.first;
            int y = it.second;

            a[x][y] = 'O';
        }
    }
};