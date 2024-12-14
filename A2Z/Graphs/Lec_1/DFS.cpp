class Solution {
  public:
  void dfs(int node, vector<vector<int>> & adj , vector<int> &vis, vector<int> &ls ){
      vis[node] = 1;
      ls.push_back(node);
      
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it, adj, vis, ls);
          }
      }
      
      
  }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis (n, 0);
        vector<int>ls;
        
        int start = 0;
        
        dfs(start, adj, vis, ls);
        
        return ls;
    }
};
