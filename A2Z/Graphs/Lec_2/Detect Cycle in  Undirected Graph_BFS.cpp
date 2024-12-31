question link:
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

class Solution {
  private:
  bool detect_cycle_bfs(vector<vector<int>>& adj, int vis[], int src){
      vis[src] = 1;
      queue<pair<int,int>>q;
      q.push({src,-1});
      while(!q.empty()){  // all the adjacency connections of the graph will be covered in the while loop
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto i : adj[node]){
              if(!vis[i]){
                  vis[i] = 1;
                  q.push({i,node});
              }
              else if(parent!=i){
                  return true;
              }
          }
      }
      return false;
  }
// BFS uses a queue to explore the nodes. 
// From the initial call, all reachable nodes are visited in one single traversal.
// BFS only needs to be called ONCE per connected component of the graph.
// For a connected graph, BFS will be called once.
// For a disconnected graph, you will start BFS for every unvisited node


  public:
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if (detect_cycle_bfs(adj,vis,i)) return true;
            }
        }
        return false;
    }
};
