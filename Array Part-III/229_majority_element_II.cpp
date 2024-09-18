/* 
    Extended Boyer Moore's Voting Algorithm
    TC: O(2n)
    SC: O(1) 
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, el1=INT_MIN, el2=INT_MIN;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2!=nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && el1!=nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            } else {
                cnt1--,cnt2--;
            }
        }

        vector<int> xp;
        int pnt1 = 0, pnt2 = 0;
        int x = (int)(n/3)+1;

        for(int i=0;i<n;i++){
            if(nums[i]==el1)pnt1++;
            else if(nums[i]==el2)pnt2++; //else if to avoid counting both elements in case they are the same.
        }
        if(pnt1>=x)xp.push_back(el1);
        if(pnt2>=x)xp.push_back(el2);
        return xp;
    }
};




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
