question link:
https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int>>> pq;
        pq.push({0,0});
        
        vector<int>vis(V,0);
        int sum=0;
        
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node] == 1) continue; //
            // theres where i add it to the mst
            vis[node] = 1;
            sum+=weight;
            for(auto it : adj[node]){
                int adjNode = it[0]; //
                int edgeW = it[1];
                if(!vis[adjNode]){
                    pq.push({edgeW,adjNode});
                }
            }
        }
        return sum;
    }
};
