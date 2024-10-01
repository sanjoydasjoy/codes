//optimal appraoch TC: O(nlogn) SC: O(n)

#include<bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int cnt=0,x=0;
    int xr=0;
    map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<a.size();i++){
        xr^=a[i];
        x=xr^b;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}



//brute force TC: O(n^2) SC: O(1)

int subarraysWithSumK(vector < int > a, int b) {
    int cnt=0;
    for(int i=0;i<a.size();i++){
        int xr=0;
        for(int j=i;j<a.size();j++){
            xr^=a[j];
            if(xr==b)cnt++;
        }
    }
    return cnt;
}
