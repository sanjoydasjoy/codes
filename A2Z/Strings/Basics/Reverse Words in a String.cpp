question link:
https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        sort(strs.begin(),strs.end());
        string ans = "";
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]==strs[strs.size()-1][i])ans+=strs[0][i];
            else break;
        }
        return ans;
    }
};
