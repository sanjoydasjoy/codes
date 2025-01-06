class Solution {
  private:
  bool bfs(vector<vector<int>>& adj, int col, vector<int>& color, int src){
      color[src] = col;
      queue<int> q;
      q.push(src);
      while(!q.empty()){
          int node = q.front();
          q.pop();
      
      for(auto it : adj[node]){
          if(color[it]==-1){
                color[it] = !color[node];
                q.push(it);
            }
          else if(color[it] == color[node]) return false;
        }
      }
      return true;
  }
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(adj,0,color,i) ==  false) return false;
            }
        }
        return true;
    }
};
