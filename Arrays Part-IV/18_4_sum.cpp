// better soln 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long>HashSet;
                for(int k=j+1;k<n;k++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        int fourth = target - sum;
                        if(HashSet.find(fourth) != HashSet.end()){
                            vector<int>temp={nums[i],nums[j],nums[k],fourth};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    HashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>>ans = {st.begin(),st.end()};
        return ans;
    }
};




//brute force TC: O(n^4) SC: O(number of quads)*2 for set and ans

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum=nums[i]+nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target){
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans = {st.begin(),st.end()};
        return ans;
    }
};
