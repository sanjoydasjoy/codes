question link:

class Solution {
public:
    int reverse(int x) {
        long reverseDigit = 0;
        while(x!=0){
            long lastDigit = x%10;
            x/=10;
            reverseDigit = reverseDigit*10 + lastDigit;
        }
        if (reverseDigit < INT_MIN || reverseDigit > INT_MAX) return 0;
        return reverseDigit;
    }
};
