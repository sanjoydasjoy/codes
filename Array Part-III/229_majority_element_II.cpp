class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n = nums.size(), mx = -1, p;
        map<int, int> mpp;
        vector<int>xp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto i : mpp) {
            if (i.second > n/3) {
                xp.push_back(i.first) ;
            }
        }
        return xp;
    }
};
