/* 
    Naive approach
    TC: O(NlogN) + O(N)  SC: O(N)
    This will distort the array.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int val=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){val=nums[i];}
        }
        return val;
    }
};

/*
    Using Hashing / Frequency array
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int val=0;
        vector<int> frequencyArr(n+1, 0); 

        for(int i=0;i<n;i++){
            if(frequencyArr[nums[i]]==0){
                frequencyArr[nums[i]]+=1;
            }
            else {val=nums[i];break;}
        }
        return val;
    }
};
