class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                    && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        if (dist[0][0] == 0 || dist[n-1][n-1] == 0) return 0;
        
        priority_queue<tuple<int,int,int>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        pq.push({dist[0][0], 0, 0});
        
        while (!pq.empty()) {
            auto [safe, r, c] = pq.top(); pq.pop();
            
            if (r == n-1 && c == n-1) return safe;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n 
                    && !visited[nr][nc]) {
                    int newSafe = min(safe, dist[nr][nc]);
                    pq.push({newSafe, nr, nc});
                }
            }
        }
        
        return 0;
    }
};