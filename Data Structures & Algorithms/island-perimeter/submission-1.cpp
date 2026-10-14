class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int output = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto it : dirs){
                int ni = i + it[0];
                int nj = j + it[1];

                if(ni>=0 && ni <n && nj>=0 && nj<m && grid[ni][nj] == 1){
                    continue;
                }
                else
                    output++;
            }
        }
        return output;

    }
};