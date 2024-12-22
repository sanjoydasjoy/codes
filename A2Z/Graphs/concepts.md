1. if theres n number of vertices, there will be nC2 edges, and 2 ^ (nC2) number of total combination of graphs that can be made 

2. vector<int> adj [N] is wrong , absolutely wrong, cause standard c++ doesnt get VLAs... it should be <br>
 vector<vector< int >> adj (n) or vector<vector< int >> adj (n, vector<int>(n,0))

3. int vis[n] = {0}; is not considered good practice in modern C++ for the following reasons:   
   The syntax int vis[n] creates a variable-length array (VLA), which is not part of the C++     
   standard (post-C++98/03). VLAs are allowed in C99 (a C standard), but in C++, array sizes must 
   be a constant expression that is determined at compile-time.

   Better Alternative: vector<int> vis(n, 0); 


## BFS - Breadth-First Search
1. the traversal of the graph proceeds level-by-level starting from a single node.
2. BFS uses a queue to explore the nodes. 
3. From the initial call, all reachable nodes are visited in one single traversal.
4. BFS only needs to be called ONCE per connected component of the graph.
5. For a connected graph, BFS will be called once.
6. For a disconnected graph, you will start BFS for every unvisited node
7. all the adjacency connections of the graph will be covered in the while loop






  
