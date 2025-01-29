question link:
https://leetcode.com/problems/single-number/

// brute force
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        for(auto it : mp)if(it.second == 1){ans = it.first; break;}
        return ans;
    }
};

// optimal using bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
