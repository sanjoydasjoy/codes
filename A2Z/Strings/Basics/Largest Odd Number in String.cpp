question link:
https://leetcode.com/problems/largest-odd-number-in-string/description/

// correct solution

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        for(int i = n-1;i>=0;i--){
            if((num[i] - '0') &1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};


// one problem with this problem is this has stoi function which throws error once the number is too long
// otrhwise this is absolutely fine

class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size();

        for(int i=0;i<n;i++){
            string p = num.substr(i,n-i);
            long long x = stoi(p);
            if(x&1)return p;
        }
        for(int i=0;i<n;i++){
            string p = num.substr(0,n-i);
            long long x = stoi(p);
            if(x&1)return p;
        }
        return "";
    }
};
