question link:
https://www.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        if (((n >> k) & 1) == 1) return true;
        return false;
    }
};
