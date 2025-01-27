class Solution{   
public:
    pair<int, int> get(int a, int b){
        // int temp = a;
        // a = b;
        // b = temp;
        
        a = a^b;
        b = a^b;
        a = a^b;
        
        return {a,b};
    }
};
