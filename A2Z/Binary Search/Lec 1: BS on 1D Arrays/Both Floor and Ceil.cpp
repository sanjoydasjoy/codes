question link:
https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor


class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        vector<int>res;
        sort(arr.begin(),arr.end());
        
        // finding floor
        
        int left = 0, right = arr.size() - 1;
        int ans = -1;
        while(left<=right){
            int mid = left + ((right - left)>>1);
            if(arr[mid] <= x){
                ans = arr[mid];
                left = mid + 1;
            }
            else right = mid - 1;
        }
        res.push_back(ans);
        
        // finding ceil == lower_bound
        
        auto it = lower_bound(arr.begin(), arr.end(), x);
        if(it == arr.end())res.push_back(-1);
        else res.push_back(arr[it - arr.begin()]);
        
        return res;
    }
};
