question link:
https://leetcode.com/problems/string-to-integer-atoi/description/


class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, result = 0, i = 0;
        
        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};


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
