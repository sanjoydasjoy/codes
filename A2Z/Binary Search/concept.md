### ❏ binary search

    private:
        int binary_search(vector<int>& nums, int target){
            int left = 0, right = nums.size() - 1;
            while(left<=right){
                int mid = left + ((right - left) >> 1);
                if(nums[mid] == target)return mid;
                else if(nums[mid] > target)right = mid-1;
                else if(nums[mid] < target)left = mid+1;
            }
            return -1;
        }


### ❏ lower bound === smallest index such that arr[ind] >= x 

    int lowerBound(vector<int> arr, int n, int x) {
        int left = 0, right = arr.size() - 1;
        int ans = n;
    
        while (left <= right) {
          int mid = left + ((right - left) >> 1);
          if (arr[mid] >= x) {
              ans = mid;
              right = mid - 1;
          } else {
              left = mid + 1;
          }
        }
     return ans; 
    }



### ❏ higher bound === smallest index such that arr[ind] >= x 
    
