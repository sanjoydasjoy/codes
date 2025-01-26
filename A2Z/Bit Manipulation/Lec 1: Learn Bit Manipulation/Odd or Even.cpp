question link:
https://www.geeksforgeeks.org/problems/odd-or-even3618/1

class Solution {
  public:
    bool isEven(int n) {
        if(n&1)return false;
        return true;
    }
};
