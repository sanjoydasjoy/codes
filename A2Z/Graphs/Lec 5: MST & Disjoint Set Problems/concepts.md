### Spanning Tree  
1. **Definition**: A spanning tree is a subgraph of a connected graph that includes all the vertices and is a tree (no cycles).  
2. **Properties**:  
   - If a graph has \( V \) vertices, the spanning tree has \( V-1 \) edges.  
   - Every connected graph can have multiple spanning trees.  

### Minimum Spanning Tree (MST)  
1. **Definition**: An MST is a spanning tree with the minimum total edge weight among all spanning trees of a weighted graph.  
2. **Algorithms**:  
   - **Prim's Algorithm**: Builds the MST by growing one vertex at a time.  
   - **Kruskal's Algorithm**: Adds edges in increasing order of weight, ensuring no cycles.  
3. **Applications**:  
   - Network design (e.g., minimizing cable costs).  
   - Approximation algorithms (e.g., TSP).
