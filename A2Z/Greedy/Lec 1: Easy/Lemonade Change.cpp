question link:
https://leetcode.com/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0, cnt20 = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)cnt5++;
            else if(bills[i]==10){
                if(cnt5==0)return false;
                cnt5--;
                cnt10++;
            }
            else if(bills[i]==20){
                if((cnt10==0 and cnt5==0) or (cnt10==0 and cnt5<3) or cnt5==0)return false;
                else {
                    if(cnt10==0){
                        cnt5 -= 3;
                    }
                    else{
                    cnt5--;
                    cnt10--;}
                }
            }
            

        }
        return true;
    }
};
