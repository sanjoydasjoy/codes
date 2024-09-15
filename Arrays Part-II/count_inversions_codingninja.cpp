#include <bits/stdc++.h>
int cnt = 0;
void merge(vector<int> &nums, int low, int mid, int high) {
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high) {
    if (nums[left] <= nums[right]) {
      temp.push_back(nums[left]);
      left++;
    } else {
      temp.push_back(nums[right]);
      right++;
      cnt += (mid - left + 1);
    }
  }
  while (left <= mid) {
    temp.push_back(nums[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(nums[right]);
    right++;
  }
  for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low, int high) {
  if (low >= high)return;
  
  int mid = (low + high) / 2;
  mergeSort(nums, low, mid);
  mergeSort(nums, mid + 1, high);
  merge(nums, low, mid, high);

}

long long getInversions(long long *arr, int n) {

  int low = 0;
  int high = n - 1;
  vector<int> nums(arr, arr + n);

  mergeSort(nums, low, high);

  return cnt;
}













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
