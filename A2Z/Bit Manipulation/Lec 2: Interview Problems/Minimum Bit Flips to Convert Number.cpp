question link: 
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/


// brute force
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int a = start, b = goal;
        int cnt = 0;
        while(a!=0 or b!=0){
            if((a & 1) != (b & 1)) cnt++;
            a = a >> 1;
            b = b >> 1;
        }
        return cnt;
    }
};


// using builtin function 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        return __builtin_popcount(x);

    }
};


// efficient approach
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int cnt = 0;
        while(x!=0){
            x = x & (x-1);
            cnt++;
        }
        return cnt;
    }
};
