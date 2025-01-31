question link:
https://www.naukri.com/code360/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

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
