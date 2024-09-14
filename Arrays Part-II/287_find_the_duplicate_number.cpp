/* 
    Naive approach
    TC: O(NlogN) + O(N)  SC: O(1)
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
    TC:  O(N)  SC: O(N)
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

/*
    Floyd's Tortoise and Hare (cycle detection) algorithm
    Linked list cycle method
    TC:  O(N)  SC: O(1)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
