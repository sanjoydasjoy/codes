// topological sort only works in DAGs (Directed Acyclic Graph)
// A cycle in the graph would violate the ordering requirement
// a linear ordering of vertices such that for every directed edge u → v, u appears before vertex v in the ordering


class Solution {
  private: 
    void dfs(vector<vector<int>>& adj,vector<int>& vis,stack<int>& st, int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj, vis, st, it);
            }
        }
        st.push(node); // only step for toposort
    }
  public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj, vis, st, i);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
