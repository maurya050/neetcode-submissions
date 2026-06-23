class Solution {
public:
    void componentVisit(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto x : adj[node]){
            if(vis[x] != 1)
                componentVisit(x, adj, vis);
            else
                continue;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        int ans = 0;

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++){
            if(vis[i] != 1){
                ans++;
                componentVisit(i, adj, vis);
            }
        }
        return ans;
    }
};
