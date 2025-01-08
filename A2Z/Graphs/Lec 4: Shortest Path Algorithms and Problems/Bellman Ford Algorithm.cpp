question link: 
https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm

// both bellman ford and dijkstra algorithms are single-source shortest path algorithms
// if there are negative edges or negative cycle in the graph, it will fail to find shortest path if we use dijsktra. 
// negative cycle: a negative cycle in a graph is a cycle where the total sum of edge weights is negative. 
// if we use dijsktra, it will keep on minimizing the distance. so djisktra doesnt help us to detect the negative cycle.
// bellman ford does that but it works only for DG (directed graph)
// so if they give us undirected graph, we have to make it directed
// u - v (5 weight) to u -> v (5 weight) and v -> u (5 weight)



class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // nth iteration to check negative cycle
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};

