question link:
https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>>ans(n); it will make extra empty arrays
        vector<vector<int>>ans;

        for(int i=0;i< (1<<n) ;i++){
            vector<int>list;
            for(int j=0;j<n;j++){
                if((i>>j)&1)list.push_back(nums[j]);
            }
            ans.push_back(list);
        }
        return ans;

    }
};
