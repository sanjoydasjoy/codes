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
