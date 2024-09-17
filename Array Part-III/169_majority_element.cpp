class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), mx = -1, p;
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto i : mpp) {
            if (i.second > mx) {
                mx = i.second;
                p = i.first;
            }
        }
        return p;
    }
};
