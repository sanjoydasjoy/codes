class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>>adj(N);
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
        }
        vector<int>indegree(N);
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        if(topo.size()==N) return true;
        return false;
    }
};
