question link: 
https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/

// using builtin function 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        return __builtin_popcount(x);

    }
};

// proper approach
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
