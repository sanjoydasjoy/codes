question link:
https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=ceil-the-floor

similar question:
https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

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


// using direct functions

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        
        // Finding floor using upper_bound - 1
        auto ub = upper_bound(arr.begin(), arr.end(), x);
        if (ub == arr.begin()) res.push_back(-1);  // No floor exists
        else res.push_back(*(ub - 1));

        // Finding ceil using lower_bound
        auto lb = lower_bound(arr.begin(), arr.end(), x);
        if (lb == arr.end()) res.push_back(-1);  // No ceil exists
        else res.push_back(*lb);
        
        return res;
    }
};

