question link:
https://www.geeksforgeeks.org/check-if-two-given-strings-are-isomorphic-to-each-other/


class Solution {
public:
    bool isIsomorphic(string s, string t) {

        vector<int>d1(256,0);
        vector<int>d2(256,0);
        
        for(int i=0;i<s.size();i++){
            char a = s[i], b = t[i];
            if(d1[a] != d2[b]) return false;
            else{
                d1[a] = d2[b] = i + 1;
            }
        }
        return true;

    }
};
