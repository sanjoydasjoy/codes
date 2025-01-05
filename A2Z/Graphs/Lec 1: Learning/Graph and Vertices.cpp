class Solution {
  public:
    long long count(int n) {
        long long x = n*(n-1);
        long long y = x/2;
        long long z = pow(2,y);
        return z;
    }
};
