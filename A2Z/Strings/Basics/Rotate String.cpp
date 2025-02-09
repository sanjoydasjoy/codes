question link:
https://leetcode.com/problems/rotate-string/description/


class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)return true;
        int n = s.size();
        string p;
            for(int i=0;i<n-1;i++){
                p+=s.substr(n-i-1,i+1);
                p+=s.substr(0,n-i-1);
                if(p==goal)return true;
                else p.clear();
            }
            return false;
        
    }
};
