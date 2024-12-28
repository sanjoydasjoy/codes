class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        set<pair<int,int>>st;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWeight = it.second;
                
                if(adjWeight + dis < dist[adjNode]){
                    dist[adjNode] = adjWeight + dis;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
        
    }
};
