/*
  Dijkstra's algorithm is similar to BFS but is designed for weighted graphs, while BFS works for unweighted graphs

  components in priority queue: 
  1. pair<int, int>: in Dijkstra's algorithm, the pair represents {distance, node}.
  2. vector<pair<int, int>>: a vector is used, which is the default container for a priority_queue, used to store elements of the priority queue.
  3. greater<pair<int, int>>: by default, a priority queue in c++ is a max-heap, meaning it retrieves the largest element first.
                              using greater<pair<int, int>> turns it into a min-heap, meaning it retrieves the smallest element first.
                              this is crucial for Dijkstra's algorithm because we want the smallest distance to process first.
                              
  The priority queue compares the first element of the pair to decide which pair comes first.
  If the first elements are the same, the second element of the pair decides the order.

   In a priority queue that is implemented as a min-heap, the smallest value (shortest distance, in the case of Dijkstra's algorithm) will always be at the top. 
   If two nodes have the same distance, then the node with the smaller node number (or the smaller value in the comparison) will be placed at the top.



*/
class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);

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
