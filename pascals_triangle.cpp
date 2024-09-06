#include <bits/stdc++.h>
using namespace std;

int nCr(int row, int column){

    int res=1;

    for(int i=0;i<column;i++){
        res *= (row-i);
        res = res / (i+1);
    }

    return res;
}
void printRow(int n){

    int x=1;
    for(int i=0;i<n;i++){
        cout<<x<<" ";
        x *= (n-(i+1));
        x /= (i+1);
        
    }

}

void printPascal(int n){

    for(int i=0;i<n;i++){
        int x=1;
        for(int j=0;j<=i;j++){
            cout<<x<<" ";
            x *= (i-j);
            x /= (j+1);
        }
        cout<<endl;
    }
}

int main()
{

    /* 
        pascal triangle element find from given row and column
        using nCr formula we can get the value instead of bruteforce 
    */

    // int n,m;cin>>n>>m;
    // cout<<nCr(n,m)<<endl;


    /*
        print entire row from given row number
    */

    //int n;cin>>n;
    //printRow(n);


    /*
        print entire pascal triangle from given row number
    */

    int n;cin>>n;
    printPascal(n);
    
    
}



//Brute force

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result(numRows);

        for (int i = 0; i < numRows; i++) {
            result[i].resize(i + 1);

            result[i][0] = 1;
            result[i][i] = 1;

            for (int j = 1; j < i; j++) {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        
        return result;
    }
};


//
