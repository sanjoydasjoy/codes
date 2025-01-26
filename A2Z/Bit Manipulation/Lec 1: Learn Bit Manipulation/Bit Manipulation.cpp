question link:
https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card&selectedLang=c

class Solution {
  public:
    void bitManipulation(int num, int i) {
        int x = num >> (i-1) & 1;
        int y = num | 1 << (i-1);
        int z = num & ~(1 << (i-1));
        cout<< x << " " << y << " " <<z;
    }
};
