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
