// Space Complexity : O(3N) ; 1 for queue, 1 for visited array, 1 for bfs array
// Time Complexity : O(N) + O(2E) ; first while loop and then in for loop it traverse the total degree

class Solution {
  public:
    
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int n = adj.size();
        int vis[n] = {0};
        vis[0] = 1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
