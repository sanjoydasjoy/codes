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
    // all neighbors are explored and no cycle is detected, return false.
    // the first time false will return is when there are no unvisited neighbors for a node, 
    // meaning the recursion reaches a "dead end" in its current path
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

/*
Pass the parent node alongside the current node in the DFS call
If a visited node is encountered and it is not the parent, a cycle exists.
Traverse all connected components to ensure no cycles are missed in a disconnected graph.

Key condition for cycle detection:
If a visited node is found (vis[i] == 1) and i != parent, it indicates a cycle.
*/



