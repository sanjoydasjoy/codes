// optimal approach

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int len=0;
    int n = a.size();
    long long sum=0;
    int l=0,r=0;
    
    while(r<n){
        sum+=a[r];
        while(sum>k){
            sum-=a[l];
            l++;
        }
        if(sum==k){
            len=max(len,r-l+1);
        }
        r++;
    }
    return len;
}


//better approach
// TC: O(n*logn) if its ordered map , SC: O(n)
// optimal approach for positives and negatives
#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int len=0;
    int n = a.size();
    long long sum=0;
    map<int,int>preSumMap;
    for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k)len=max(len,i+1);
            int rem=sum-k;
            if(preSumMap.find(rem)!=preSumMap.end()){
                int p = i-preSumMap[rem];
                len=max(len,p);
            }
            if(preSumMap.find(sum)==preSumMap.end())preSumMap[sum]=i;
        
    }
    return len;
}


// brute force O(n^2)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int len=0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k)len=max(len,j-i+1);
        }
    }
    return len;
}
