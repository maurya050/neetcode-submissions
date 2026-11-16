class Solution {
public:
    void mapIsland(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(auto dir : dirs){
            int ni = i +  dir[0];
            int nj = j + dir[1];
            if(ni>=0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && vis[ni][nj] == -1){
                vis[ni][nj] = 1;
                mapIsland(ni, nj, n, m, grid, vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, -1));

        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    vis[i][j] = 1;
                    mapIsland(i, j, n, m, grid, vis);
                    count++;
                }
            }
        }
        return count;
    }
};
