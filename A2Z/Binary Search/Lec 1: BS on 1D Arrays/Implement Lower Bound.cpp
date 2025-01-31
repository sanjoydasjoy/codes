question link:
https://www.naukri.com/code360/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM


int lowerBound(vector<int> arr, int n, int x) {
	int left = 0, right = arr.size() - 1, mid = 0;
	int ans = n;
	while(left<=right){
		int mid = left + ((right-left)>>1);
		if(arr[mid] >= x){
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

int lowerBound(vector<int> arr, int n, int x) {
	int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
	return lb;
}
