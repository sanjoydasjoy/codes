// brute force TC: O(n^2) SC: O(1)

#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])cnt++;
        }
    }
    return cnt;
}
