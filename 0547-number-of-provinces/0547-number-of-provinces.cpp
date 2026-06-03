class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        visited[node] = 1;

        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& a) {
        int V = a.size();

        vector<vector<int>> adjList(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (a[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};