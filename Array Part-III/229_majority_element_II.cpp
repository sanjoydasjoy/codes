/* 
    hashing soln
    TC: O(nlogn) // for ordered map
    SC: O(n) 
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         int n = nums.size();
        map<int, int> mpp;
        vector<int>xp;

        int x = (int)(n/3) + 1;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            
            if (mpp[nums[i]] == x) {  // because elements that appear more than ⌊ n/3 ⌋ times
                xp.push_back(nums[i]);
            }
            if(xp.size()==2)break;
        }
        return xp;
    }
};
