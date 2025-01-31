question link:
https://leetcode.com/problems/binary-search/submissions/1526385565/

class Solution {
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
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums,target);
    }
};
