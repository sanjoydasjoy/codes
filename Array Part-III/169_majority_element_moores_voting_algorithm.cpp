
/* 
    hashing solution - better soln
    TC: O(nlogn) + O(n) 
    SC: O(n) // if all the elements in the array is unique

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), mx = -1, p;
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        for (auto i : mpp) {
            if (i.second > n/2) {
                return i.first;
            }
        }
        return -1;
    }
};
