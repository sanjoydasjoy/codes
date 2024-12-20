class Solution {
private:
    bool dfs(vector<vector<int>>& graph, int col, vector<int>& color, int node){
        color[node] = col;
        for(auto it : graph[node]){
            if(color[it] == -1){
                if(!dfs(graph, !col, color, it)) return false;
            }
            else if(color[it] ==  col) return false;
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
