question link:
https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

class Solution {
  public:
    int findFloor(vector<int>& arr, int k) {

        int left = 0, right = arr.size() - 1;
        int ans = -1;
        while(left<=right){
            int mid = left + ((right - left) >> 1);
            if(arr[mid] <= k){
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return ans;
    }
};
