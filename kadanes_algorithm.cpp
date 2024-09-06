//Brute force


#include <bits/stdc++.h>
using namespace std;

int Max_subarray(vector<int>v,int n){
    int max_sum = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=v[k];
            }
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
}

int main()
{

    int n;cin>>n;
    vector<int>arr(n+1);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x = Max_subarray(arr, n);
    cout<<x;
    
}




