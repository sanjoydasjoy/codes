question link: 
https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 and !(n & (n-1))) return true;
        return false;
    }
};
