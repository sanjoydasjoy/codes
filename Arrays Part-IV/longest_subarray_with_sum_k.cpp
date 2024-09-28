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
