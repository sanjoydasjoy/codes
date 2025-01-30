question link:
https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int p = n;
        if(p<0)p=-p;
        while(p>0){
            if(p&1){
                ans*=x;
                p-=1;
            }
            else{
                x*=x;
                p/=2;
            }
        }
        if(n>0)return ans;
        return (1/ans);
    }
};
