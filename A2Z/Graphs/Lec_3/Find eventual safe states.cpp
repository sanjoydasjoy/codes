class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<vector<int>>adjj(V);
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            // this is i -> it
            // we need it -> i
            for(auto it:adj[i]){
                adjj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adjj[node]){
                indegree[it]--;
                if(!indegree[it]){
                q.push(it);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
        
        
    }
};
