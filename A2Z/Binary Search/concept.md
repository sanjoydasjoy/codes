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

---
<br><br>

### ❏ lower bound === smallest index such that arr[ind] >= x 

      arr = [1, 2, 4, 4, 4, 6, 7, 9, 9, 10, 15]
            [0  1  2  3  4  5  6  7  8   9  10]
	    x = 4 → index = 2; x = 5 → index = 5; x = 9 → index = 7
     	    x = 11 → index = 10; x = 20 → index = 11


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

    // using builtin function
    
    int lowerBound(vector<int> arr, int n, int x) {
	    int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	    return lb;
    
    }

    // for special range [l, r]
    
    int lowerBound(vector<int>& arr, int l, int r, int x) {
        int it = lower_bound(arr.begin() + l, arr.begin() + r + 1, x) - arr.begin();
        return it; 
    }

---

<br><br>
### ❏ upper bound === smallest index such that arr[ind] > x 

	arr = [2, 3, 6, 7, 8, 8, 11, 11, 11, 12]
 	      [0  1  2  3  4  5   6   7   8   9]
 	x = 6, index = 3; x = 11, index = 9; x = 12/13, index = 10

  	int upperBound(vector<int> &arr, int x, int n){
	
		int left = 0, right = arr.size() - 1;
		int ans = n;
		while(left<=right){
			int mid = left + ((right - left) >> 1);
			if(arr[mid] > x){
				ans = mid;
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		return ans;	
	}

	// using built in function

	int upperBound(vector<int> &arr, int x, int n){
		int ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
		return ub;
	}

---

<br><br>

### ❏ lower bound - upper bound table
```
arr = [1, 2, 4, 4, 4, 6, 7, 9, 9, 10, 15]
      [0  1  2  3  4  5  6  7  8   9  10]
```

|  x   |  lower_bound (arr[ind] ≥ x) |  upper_bound  (arr[ind] > x) |
|------|-----------------------------|-----------------------------|
|  4   |  2   (First occurrence of  4 )  |  5   (First  >4  is  6 )  |
|  5   |  5   (First  ≥5 is  6 )  |  5   (First  >5  is  6 )  |
|  6   |  5   (First occurrence of  6 )  |  6   (First  >6  is  7 )  |
|  9   |  7   (First occurrence of  9 )  |  9   (First  >9  is  10 ) |
|  10  |  9   (First occurrence of  10 ) |  10  (First  >10  is  15 ) |
|  12  |  10  (First  ≥12  is  15 ) |  10  (First >12  is  15 ) |
|  15  |  10  (First occurrence of  15 ) |  11  (Out of bounds) |

---

<br><br>

### ❏ floor and ceil in sorted array

 - floor = largest number in sorted array <= x   -> [this is reverse of lower bound] <br>
 - ceil = smallest number in sorted array >= x   -> [this is lower bound] <br>
