// if there are negative edges or negative cycle in the graph, it will fail to find shortest path if we use dijsktra. 
// negative cycle: a negative cycle in a graph is a cycle where the total sum of edge weights is negative. if we use dijsktra, it will keep on minimizing the distance
// so djisktra doesnt help us to detect the negative cycle.
// bellman ford does that but it works only for DG (directed graph)
// so if they give us undirected graph, we have to make it directed
// u - v (5 weight) to u -> v (5 weight) and v -> u (5 weight)
// both Bellman-Ford and Dijkstra's algorithms are single-source shortest path algorithms




