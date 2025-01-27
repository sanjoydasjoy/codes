question link:
https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

brute force:

class Solution{
    public:
    int countSetBits(int n)
    {
        int cnt =0;
        for (int i = 1; i <= n; i++){
        int num = i;
        while(num>1){
            cnt += num&1;
            num = num>>1;
        }
        if(num==1)cnt++;
        }
        return cnt;
        
    }
};
