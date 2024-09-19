/* 
    moore's voting algorithm
    TC: O(n) 
      + O(n) [in case the majority element not everytime exists]
    SC: O(1) 

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int el=nums[0],cnt=0,pnt=0;
        int n = nums.size();
        for(int i=0;i<n;i++){

            if(cnt == 0){ cnt=1, el = nums[i];}

            else if(nums[i] == el) cnt++;
            
            else cnt--;

        }
        /*  in case the majority element not everytime exists
        for(int i=0;i<n;i++){
            if(nums[i]==el)pnt++;
        }
        if(pnt>n/2)return el; */
        
        return el;
        
    }
};

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
