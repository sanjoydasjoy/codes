question link:
https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-xor-of-numbers-from-l-to-r

// this will give error cause the next if will never execute
class Solution {
  public:
    int findXOR(int l, int r) {
        int x,y;
        if (l % 4 == 0) x = l;
        else if (l % 4 == 1) x = 1;
        else if (l % 4 == 2) x = l + 1;
        else x = 0;
        
        if (r % 4 == 0) y = r;
        else if (r % 4 == 1) y = 1;
        else if (r % 4 == 2) y = r + 1;
        else y = 0;
        
        return x^y;
    }
};


// correct

class Solution {
public:
    int findXOR(int l, int r) {
        int xorUpTo(int n) {
            if (n % 4 == 0) return n;
            if (n % 4 == 1) return 1;
            if (n % 4 == 2) return n + 1;
            return 0; // n % 4 == 3
        }

        return xorUpTo(r) ^ xorUpTo(l - 1);
    }
};
