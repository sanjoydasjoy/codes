// optimal approach without distorting the array
// TC: O(n) for inserting into unordered set
//    +O(2n) for total of 14 iteration if we consider this array 102 4 100 1 101 3 2 
//    so total of O(n) + O(2n) = O(3n) under the assumption of unordered set taking O(1) for inserting and finding (except best and avg case)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int cnt = 1;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt = cnt + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
        }
    };
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
