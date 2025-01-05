class Solution {
  public:
    
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<int>adj[V+1];
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            adj[edges[i].first].push_back(edges[i].second);
            adj[edges[i].second].push_back(edges[i].first);
        }

       
        vector<vector<int>> result(V);
        for (int i = 0; i < V; i++) {
            result[i] = adj[i];
        }

        return result;
    }
};
