question link:
https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1?utm_source=youtube&amp%3Butm_medium=collab_striver_ytdescription&amp%3Butm_campaign=all-divisors-of-a-number

class Solution {
  public:
    void print_divisors(int n) {
        vector<int>ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                ans.push_back(i);
                if(n/i != i){
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it : ans)cout<<it<<" ";
    }
};
