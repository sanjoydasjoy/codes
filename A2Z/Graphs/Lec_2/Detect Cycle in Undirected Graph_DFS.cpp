class Solution {
  private: 
  bool detect_cycle_dfs(vector<vector<int>>& adj, int vis[], int node, int parent){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(!vis[i]){
                if(detect_cycle_dfs(adj,vis,i,node)) return true;
            }
            else if(parent != i) return true;
        }
        return false;
  }
  public:
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detect_cycle_dfs(adj,vis,i,-1)) return true;
            }
        }
        return false;
    }
};
