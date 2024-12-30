question link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> adj) {
         vector<int>indegree(V,0);
         for(int i=0;i<V;i++){
             for(auto it : adj[i]){
                 indegree[it]++;
             }
         }
         queue<int>q;
         for(int i=0;i<V;i++){
             if(indegree[i]==0){
                 q.push(i);
             }
         }
         //vector<int>ans;
         int cnt=0;
         while(!q.empty()){
             int node = q.front();
             q.pop();
             //ans.push_back(node);
             cnt++;
             for(auto it : adj[node]){
                 indegree[it]--;
                 if(indegree[it]==0)q.push(it);
             }
         }
         if(cnt==V)return false;
         return true;
    }
};
