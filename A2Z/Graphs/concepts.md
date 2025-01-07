## Basics
1.

        if theres n number of vertices, there will be nC2 edges,
        and 2 ^ (nC2) number of total combination of graphs that can be made 

3.

      vector<int> adj [N] is wrong , absolutely wrong, cause standard c++ doesnt get VLAs. it should be 
      vector<vector< int >> adj (n) or vector<vector< int >> adj (n, vector<int>(n,0))

4.

      vector<vector<int>> adj(n) : 2D vector with n rows, but each row is initially an empty vector
      vector<vector<int>> adj(n, vector<int>(n, 0)) : 2D vector with n rows, each containing n elements initialized to 0

          its better to take (n+1,0); in case its 1 base indexing

6.   

           if you give vector<vector<int>>adj, it will give segmentation error. it should always be vector<vector<int>>adj(k)
7.

      int vis[n] = {0}; is not considered good practice in modern C++ for the following reasons:   
      The syntax int vis[n] creates a variable-length array (VLA), which is not part of the C++     
      standard (post-C++98/03). VLAs are allowed in C99 (a C standard), but in C++, array sizes must 
      be a constant expression that is determined at compile-time.

      Better Alternative: vector<int> vis(n, 0);

8. **how adjacency list is stored:** <br>
   given format: in edge style <br>
   
       5 4 -> n,m 
       1 2 
       2 3 
       3 4 
       4 5

       corresponding code for storing the graph:
       
       vector<vector<int>> adj(n + 1); // n number of nodes
       for (int i=0;i<m;i++){ // m number of edges 
           int u,v; 
           cin>>u>>v;  
           adj[u].push_back(v);  // For directed graph 
           adj[v].push_back(u);  // For undirected graph
        }
   
       **The 2D vector adj will look like this in memory storage:**

       adj[1] → [2]      // Node 1 is connected to Node 2
       adj[2] → [1, 3]   // Node 2 is connected to Nodes 1 and 3
       adj[3] → [2, 4]   // Node 3 is connected to Nodes 2 and 4
       adj[4] → [3, 5]   // Node 4 is connected to Nodes 3 and 5
       adj[5] → [4]      // Node 5 is connected to Node 4
   


       now for weighted graphs
       5 4
       1 2 10  
       2 3 15  
       3 4 20  
       4 5 25

       corresponding code for storing the graph:

       vector<vector<pair<int, int>>> adj(n + 1); // n nodes, adjacency list for weighted graph
        for (int i = 0; i < m; i++) {              // m edges
            int u, v, w;
            cin >> u >> v >> w;                    // u and v are nodes, w is weight
            adj[u].push_back({v, w});              // Directed edge
            adj[v].push_back({u, w});              // Undirected edge
        }

        **This how the 2D vector adj will look like this in memory storage:**

        adj[1] → [(2, 10)]            // Node 1 is connected to Node 2 with weight 10
        adj[2] → [(1, 10), (3, 15)]   // Node 2 is connected to Nodes 1 (weight 10) and 3 (weight 15)
        adj[3] → [(2, 15), (4, 20)]   // Node 3 is connected to Nodes 2 (weight 15) and 4 (weight 20)
        adj[4] → [(3, 20), (5, 25)]   // Node 4 is connected to Nodes 3 (weight 20) and 5 (weight 25)
        adj[5] → [(4, 25)]            // Node 5 is connected to Node 4 with weight 25


           ** new style for weighted graph:
           Input:
                3 3
                0 1 5
                1 2 3
                0 2 1
           input is like that and the given adj list format is- int spanningTree(int V, vector<vector<int>> adj[]) {

           since we have learnt that the proper way to store weighted graph is vector<vector<pair<int, int>>> adj(V)

           this will not store like it was previously

           instead, it will store as adj[i] -> [[node, weight], [node, weight]]
                adj[0] -> [[1, 5], [2, 1]]
                adj[1] -> [[0, 5], [2, 3]]
                adj[2] -> [[1, 3], [0, 1]]

           and thats how we can access em

                vector<pair<int, pair<int, int>>> edges;
                    for(int i = 0;i<V;i++) {
                        for(auto it : adj[i]) {
                           int adjNode = it[0];
                           int wt = it[1];
                           int node = i;
                           edges.push_back({wt, {node, adjNode}});
                    }
            }

   



                



           


<br> <br>

5. **how adjacency matrix is stored:** <br>
   given format: in edge style <br>
   
   
       5 4 -> n,m 
       1 2 
       2 3 
       3 4 
       4 5

       corresponding code for storing the graph:
       
       vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
   
          /* In adjacency matrix, the matrix is always n x n because:
              the matrix needs to record whether there is a connection between every pair of nodes.
              for a graph with n nodes, recording connections for all possible pairs, i.e., n x n entries. */

       for (int i = 0; i < m; i++) {
         int u,v;
         cin>>u>>v; 
         adjMat[u][v] = 1;  // Mark edge from u to v
         adjMat[v][u] = 1;  // Mark edge from v to u (undirected graph)
       }
   
       **adjacency matrix storage in memory:**

            1  2  3  4  5
         -----------------
       1 |  0  1  0  0  0
       2 |  1  0  1  0  0
       3 |  0  1  0  1  0
       4 |  0  0  1  0  1
       5 |  0  0  0  1  0



<br> <br>


## BFS - Breadth-First Search

1. The traversal of the graph proceeds level-by-level starting from a single node.
2. BFS uses a queue to explore the nodes.
3. All the adjacency connections of the graph will be covered in the while loop
4. From the initial call, all reachable nodes are visited in one single traversal.
5. BFS only needs to be called ONCE per connected component of the graph.
6. For a connected graph, BFS will be called once.
7. For a disconnected graph, you will start BFS for every unvisited node


<br> <br>

## DFS - Depth-First Search

1. The traversal proceeds along a single branch (or path) as deeply as possible before backtracking.
2. DFS can be implemented recursively or using a stack.
3. The recursion propagates through all neighbors of the current node before backtracking.

<br> <br>

## Key Difference in Calls
1. BFS is "called once" because it uses a single iterative process with a queue, and there’s no explicit recursion.
2. DFS involves recursive calls for each branch, so it seems like it's called many times

<br> <br>

## Some Observations
 CYCLE <br>
1. For cycle detection, returning true (cycle) is the outlier because most graphs are acyclic.
2. The default assumption is that graphs are acyclic (e.g., DAGs). So the algorithm focuses on identifying the rare case of a cycle.
<br> <br>
BIPARTITE <br>
1. Most graphs are bipartite, especially if you randomly check graphs or trees (which are always bipartite).
2. False is the outlier because it represents an exceptional case where the graph violates bipartite conditions.
3. The function is designed to return true for the majority (bipartite) cases and false only when the outlier condition (not bipartite) is detected.
4. The default assumption is that graphs are bipartite. The algorithm focuses on identifying the rare case where it's not bipartite.



<br> <br>

