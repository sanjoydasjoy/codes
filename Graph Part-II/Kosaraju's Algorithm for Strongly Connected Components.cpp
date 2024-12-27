problem link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
Steps of Kosaraju’s Algorithm:
1. Perform a DFS to determine the finishing order of nodes:

Explore the graph using Depth First Search (DFS).
Push nodes onto a stack in the order of their finish times (post-order traversal).
This step ensures that nodes from one SCC are finished before moving to another disconnected component.

2. Transpose the graph:

Reverse the direction of all edges in the graph to create the transpose graph.
This step inverts the graph's connectivity while preserving SCC relationships.

3. Perform DFS on the Transpose Graph:

Process nodes in the order defined by the stack (from the highest finish time to the lowest).
Each DFS call discovers all nodes in an SCC since the reversed edges make the SCC self-contained.
Each DFS traversal represents one SCC.

*/

class Solution {
  private: 
    void dfs(vector<vector<int>> &adj, vector<int>& vis, stack<int>& st, int node){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(adj,vis,st,it);
            }
        }
        st.push(node);
    }
    void reverse_dfs(vector<vector<int>> &transpose, vector<int>& vis, int node){
        vis[node] = 1;
        for(auto it:transpose[node]){
            if(!vis[it]){
                reverse_dfs(transpose,vis,it);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,st,i);
            }
        }
        vector<vector<int>>transpose(n);
        for(int u=0;u<n;u++){
            vis[u] = 0;
            for (int v : adj[u]) {
            transpose[v].push_back(u);
        }
            
        }
        int cnt=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                reverse_dfs(transpose,vis,node);
            }
        }
        return cnt;
    }
};



//if i had to print the scc nodes


class Solution {
  private: 
    // Perform DFS and push nodes to stack to store their finish order
    void dfs(vector<vector<int>> &adj, vector<int>& vis, stack<int>& st, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, st, it);
            }
        }
        st.push(node); // Push the node to stack after exploring all its neighbors
    }

    // Perform DFS on the transpose graph and print the nodes of each SCC
    void reverse_dfs(vector<vector<int>> &transpose, vector<int>& vis, int node, vector<int>& scc){
        vis[node] = 1;
        scc.push_back(node); // Add node to the current SCC
        for(auto it: transpose[node]){
            if(!vis[it]){
                reverse_dfs(transpose, vis, it, scc);
            }
        }
    }

  public:
    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, st, i);
            }
        }
        vector<vector<int>> transpose(n);
        for(int u = 0; u < n; u++){
            vis[u] = 0; // Reset the visited array
            for (int v : adj[u]) {
                transpose[v].push_back(u); /
            }
        }

        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                vector<int> scc; /
                reverse_dfs(transpose, vis, node, scc);
                cout << "SCC " << cnt << ": ";
                for (int n : scc) {
                    cout << n << " ";
                }
                cout << endl; 
            }
        }
    }
};

// another way

class Solution {
  private: 
    // Perform DFS and push nodes to stack to store their finish order
    void dfs(vector<vector<int>> &adj, vector<int>& vis, stack<int>& st, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, st, it);
            }
        }
        st.push(node); // Push the node to stack after exploring all its neighbors
    }

    // Perform DFS on the transpose graph and print the nodes of each SCC
    void reverse_dfs(vector<vector<int>> &transpose, vector<int>& vis, int node){
        vis[node] = 1;
        cout << node << " "; // Print node as part of current SCC
        for(auto it: transpose[node]){
            if(!vis[it]){
                reverse_dfs(transpose, vis, it);
            }
        }
    }

  public:
    void kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;

        // Step 1: DFS on the original graph and push nodes to stack in finish order
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, st, i);
            }
        }

        // Step 2: Compute the transpose of the graph
        vector<vector<int>> transpose(n);
        for(int u = 0; u < n; u++){
            for (int v : adj[u]) {
                transpose[v].push_back(u); // Reverse the edge
            }
        }

        // Step 3: Perform DFS on transpose graph in the order of stack
        fill(vis.begin(), vis.end(), 0); // Reset the visited array
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                // New SCC found; print its nodes
                reverse_dfs(transpose, vis, node);
                cout << endl; // End of current SCC
            }
        }
    }
};

