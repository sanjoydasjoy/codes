//optimal using kadanes algo

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MIN;
        int mini = prices[0];
        int n = prices.size();

        for (int i = 1; i < n; i++) {

            int cost = prices[i] - mini;
            maxi = max(maxi, cost);
            mini = min(mini, prices[i]);
        }
        if (maxi > 0)
            return maxi;
        return 0;
    }
};




//brute force

#include <bits/stdc++.h>
using namespace std;

int max_profit(vector<int>v,int n){

    int maxi = INT_MIN;
    int maax = INT_MIN;

    for(int i=0;i<n;i++){
        
        int maax = *max_element(v.begin() + i, v.end());
        if(maax>v[i]){
            int x = maax - v[i];
            if(x > maxi){
                maxi = x;
            }
        }
    }
    if(maxi>0)return maxi;
    return 0;
}

int main()
{

    int n;cin>>n;
    vector<int>arr(n+1);
    for(int i=0;i<n;i++)
        cin>>arr[i];


    int x = max_profit(arr, n);
    cout<<x;
    
}
