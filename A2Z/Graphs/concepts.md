## Basics
1. if theres n number of vertices, there will be nC2 edges, and 2 ^ (nC2) number of total combination of graphs that can be made 

2. vector<int> adj [N] is wrong , absolutely wrong, cause standard c++ doesnt get VLAs... it should be <br>
 vector<vector< int >> adj (n) or vector<vector< int >> adj (n, vector<int>(n,0))

3. int vis[n] = {0}; is not considered good practice in modern C++ for the following reasons:   
   The syntax int vis[n] creates a variable-length array (VLA), which is not part of the C++     
   standard (post-C++98/03). VLAs are allowed in C99 (a C standard), but in C++, array sizes must 
   be a constant expression that is determined at compile-time.

   Better Alternative: vector<int> vis(n, 0); 

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

