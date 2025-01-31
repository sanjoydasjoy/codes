question link:
https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, cnt = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(j<s.size() and i<g.size()){
            if(s[j] >= g[i]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
