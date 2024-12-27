/*
  Dijkstra's algorithm is similar to BFS but is designed for weighted graphs, while BFS works for unweighted graphs
*/
class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i = 0;i<V; i++) dist[i] = 1e9;

        dist[src] =0;
        pq.push({0,src});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]) {
                int edgeWeight = it.second;
                int adjNode = it.first;

                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode]=dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

    return dist;
    }
};
