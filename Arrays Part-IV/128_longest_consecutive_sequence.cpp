// better solution TC: O(nlogn) + O(n)  //but in this we are distorting the array
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=1;
        int longest= 1;
        int lastsmall = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==lastsmall){
                lastsmall=nums[i];
            }
            else if(nums[i]==lastsmall+1){
                cnt++;
                lastsmall=nums[i];
                longest=max(longest,cnt);
            }
            else if(nums[i]!=lastsmall+1){
                cnt=1;
                lastsmall=nums[i];
            }
            longest=max(longest,cnt);
        }
        return longest;
    }
};
