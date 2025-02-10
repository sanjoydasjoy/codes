question link:
https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        vector<string>ss;
        string q,p;

        for(int i=0;i<s.size();i++){
            if(s[i]!=' ')q+=s[i];
            else{
                if(q.size()>0){ss.push_back(q);q.clear();}
                else continue;
            }
        }
        if(q.size() > 0) {  
            ss.push_back(q);
        }
        for(int i=ss.size()-1;i>=0;i--){
            p+=ss[i];
            if(i!=0) p += " ";
        }
        return p;

    }
};
