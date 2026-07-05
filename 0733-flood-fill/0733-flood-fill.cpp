class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {

        int og = a[sr][sc];
        if (og == color) return a;

        int m = a.size();
        int n = a[0].size();

        queue<pair<int,int>> q;
        q.push({sr, sc});
        a[sr][sc] = color;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    a[nx][ny] == og) {

                    a[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return a;
    }
};