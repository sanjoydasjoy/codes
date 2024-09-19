// optimized using count conversion with extra function

class Solution {
public:
    void merge(vector<int>&nums,int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
                temp.push_back(nums[left]);
                left++;
        }
        while(right<=high){
                temp.push_back(nums[right]);
                right++;
        }
        for (int i=low;i<=high;i++) {
            nums[i] = temp[i-low];
        }
    }
    int countPairs(vector<int>&nums, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;
        for(int i=low;i<=mid;i++){
            
            while(right<=high && nums[i] > 2LL*nums[right])right++;
            cnt += right - (mid+1);
        }
        return cnt;
    }

    int mergeSort(vector<int>&nums,int low, int high){
        int cnt = 0;
        if(low>=high)return cnt;
        
        int mid = low + (high-low) / 2;

        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        cnt += countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums,0,nums.size()-1);

    }
};




// optimized but used cnt as global variable

class Solution {
public:
    int cnt=0;
    void merge(vector<int>&nums,int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
                temp.push_back(nums[left]);
                left++;
        }
        while(right<=high){
                temp.push_back(nums[right]);
                right++;
        }
        for (int i=low;i<=high;i++) {
            nums[i] = temp[i-low];
        }
    }
    void countPairs(vector<int>&nums, int low, int mid, int high){
        int right = mid + 1;
        for(int i=low;i<=mid;i++){
            
            while(right<=high && nums[i] > 2*nums[right])right++;
            cnt += right - (mid+1);
        }
    }

    void mergeSort(vector<int>&nums,int low, int high){
        if(low>=high)return;
        
        int mid = low + (high-low) / 2;

        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        countPairs(nums,low,mid,high);
        merge(nums,low,mid,high);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);

        return cnt;
    }
};

// brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] > (2LL * nums[j]) )cnt++;
            }
        }
        return cnt;
    }
};
