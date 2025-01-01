question link:
https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

// The problem revolves around determining a valid order of characters, which is a classic use case for topological sorting in directed acyclic graphs (DAG).
// You build a directed graph where: each node represents a character in the alphabet. A directed edge u -> v means u comes before v in the alien language.
// Constructing the graph requires comparing consecutive words in the dictionary and finding the first mismatching character.
// and then just bfs (kahns algoritm)


// points to be noted: 
// i initially wanted to use char in the adjacency list but switched to int for simplicity. 
// This is a key design decision in problems where data can be represented more efficiently.
// if you give vector<vector<int>>adj, it will give segmentation error. it should always be vector<vector<int>>adj(k)
// Mapping characters to indices (e.g., 'a' -> 0, 'b' -> 1) by adj[s1[j] - 'a'].push_back(s2[j] - 'a');
// Always initialize the graph with the expected size (vector<vector<int>>(k) for k nodes).
// 





class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        int n =  dict.size();
        vector<vector<int>>adj(k);
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            for(int j=0;j<min(s1.size(), s2.size());j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
        
        vector<int>indegree(k,0);
        for(int i=0;i<adj.size();i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<k;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        string topo;
        while(!q.empty()){
            char node = q.front();
            q.pop();
            topo+=(char)(node+'a');
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        if (topo.size() < k) return "";
        return topo;
    }
};
