//c++ built in 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

// optimal solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index==-1) reverse(nums.begin(),nums.end());
        else{
            for(int i=n-1;i>index;i--){
                if(nums[i]>nums[index]){swap(nums[i],nums[index]);break;}
            }
            reverse(nums.begin()+index+1,nums.end());
        }
    }
};
