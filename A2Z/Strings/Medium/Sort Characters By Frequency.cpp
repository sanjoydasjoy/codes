question link:
https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]]++;
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        string ans;
        for(int i=vec.size()-1;i>=0;i--){
            int x = vec[i].second;
            for(int j=0;j<x;j++)ans+=vec[i].first;
        }
        return ans;     
        
    }
};
