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



// better soln

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int n = nums.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
        
    }
};



//optimal soln - [kadanes algorithm]

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum=0;
        int n = nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum>max_sum)max_sum=sum;

        if(sum<0)sum=0;
    }
    return max_sum;
        
    }
};
