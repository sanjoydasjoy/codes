1. Most graphs are bipartite, especially if you randomly check graphs or trees (which are always bipartite).
2. False is the outlier because it represents an exceptional case where the graph violates bipartite conditions.
3. The function is designed to return true for the majority (bipartite) cases and false only when the outlier condition (not bipartite) is detected.
4. The default assumption is that graphs are bipartite. The algorithm focuses on identifying the rare case where it's not bipartite.

    
class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int col, vector<int>& color, int node){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!dfs(graph, !col, color, it)) return false;
            }
            else if(color[it] ==  col) return false;
            // else if(col[it] == color[node]) return false; this also works
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(graph, 0, color, i) == false) return false;
            }
        }
        return true;
    }
};
