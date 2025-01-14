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


// for to run in the ide

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> vis(V, 0);
        int sum = 0;

        while (!pq.empty()) {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node]) continue;
            vis[node] = 1;
            sum += weight;

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeW = it[1];
                if (!vis[adjNode]) {
                    pq.push({edgeW, adjNode});
                }
            }
        }

        return sum;
    }
};

void addEdge(vector<vector<int>> adj[], int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    Solution obj;
    cout << obj.spanningTree(V, adj) << endl;

    return 0;
}

// and test cases

5 6
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7

// if it was asked to return the mst array
// to print the edges in the Minimum Spanning Tree (MST), 
// this can be achieved by maintaining a parent vector or directly storing the edges in a list during the process.



 public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, -1}});
        vector<int> vis(V, 0);
        int sum = 0;
        vector<pair<int, int>> mstEdges;

        while (!pq.empty()) {
            int weight = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            if (vis[node] == 1) continue;

            vis[node] = 1;
            sum += weight;

            if (parent != -1) {
                mstEdges.push_back({parent, node});
            }

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeW = it[1];
                if (!vis[adjNode]) {
                    pq.push({edgeW, {adjNode, node}});
                }
            }
        }

        for (auto edge : mstEdges) {
            cout << edge.first << " - " << edge.second << endl;
        }

        return sum;
    }
};
 
  
  
