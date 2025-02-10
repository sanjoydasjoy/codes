question link:
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/


class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0, ans = -1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '('){
                cnt++;
                ans = max(ans,cnt);
            }
            else if(s[i] == ')')cnt--;
            else continue;
        }
        if(s.size() == 1 or ans == -1)return 0;
        return ans;
    }
};
