question link:
https://leetcode.com/problems/search-insert-position/description/\

/// this was old childish code !


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)return i;
        }
        if(target>nums[nums.size()-1])return nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(target>nums[i] and target<nums[i+1])return i+1;
        }
        return 0;
    
};
};


//// binary search

question link:
https://www.naukri.com/code360/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION

int binary_search(vector<int>& arr, int m){
	int left = 0, right = arr.size() - 1;
	while(left<=right){
		int mid = left + ((right - left)>>1);
		if(arr[mid] == m) return mid;
		else if(arr[mid] > m) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}
int searchInsert(vector<int>& arr, int m)
{
	if(!arr.size())return 0;
	auto it = upper_bound(arr.begin(),arr.end(),m);
	if(binary_search(arr,m) != -1) return binary_search(arr,m);
	return it - arr.begin();

}

// another 
int binary_search(vector<int>& arr, int m){
	int left = 0, right = arr.size() - 1;
	int ans = arr.size();
	while(left<=right){
		int mid = left + ((right - left)>>1);
		if(arr[mid] >= m) {ans = mid; right = mid - 1;}
		else left = mid + 1;
	}
	return ans;
}
int searchInsert(vector<int>& arr, int m)
{
	if(!arr.size())return 0;
	return binary_search(arr,m);
}
