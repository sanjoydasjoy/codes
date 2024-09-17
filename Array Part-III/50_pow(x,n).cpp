//optimal
class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        long long p = n;
        if(n<0)p=-p;


        while(p>0){
            if(p%2==1){
                ans *= x;
                p = p-1;
            }
            else {
                x *= x;
                p /= 2;
            }
        }
        
        
        if(n>0)return ans;
        else return (1/ans);
        
    }
};


//brute force
class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;

        if(n>0) for(double i=1;i<=n;i++)ans*=x;
        
        else for(double i=1;i<=(-n);i++)ans*=x;
        
        
        if(n>0)return ans;
        else return (1/ans);
        
    }
};


