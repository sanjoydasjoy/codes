question link:
https://leetcode.com/problems/string-to-integer-atoi/description/

// but stoi throws error
class Solution {
public:
    int myAtoi(string s) {
        int sign = 0, cnt = 0;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (cnt) break; 
                continue; 
            }
            if (s[i] == '-') {
                if (cnt || sign) break; 
                sign = -1;          
            } else if (s[i] == '+') {
                if (cnt || sign) break;  
                sign = 1;     
            }
            else if (isdigit(s[i])) {
                ans += s[i];
                cnt++;
            } else {
                break; 
            }
        }

        if (ans.empty()) return 0;  
        

        int result = stoi(ans);
        
        return sign == -1 ? -result : result;
    }
};
