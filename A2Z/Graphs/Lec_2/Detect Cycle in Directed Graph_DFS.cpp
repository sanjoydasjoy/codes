class Solution {
  private:
  bool dfs(vector<vector<int>> adj, vector<int>&vis, vector<int>&path_tracker, int node){
      vis[node] = 1;
      path_tracker[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it]){
              if(dfs(adj, vis, path_tracker, it)) return true;
          }
          else if(path_tracker[it] == 1) return true;
      }
      path_tracker[node] = 0; 
      return false;
  }
// path_tracker[node] = 0; is executed when the DFS finishes exploring all neighbors of the node.
// 
  public:
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        vector<int>path_tracker(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(adj, vis, path_tracker, i))return true;
            }
        }
        return false;
    }
};
