// HashMap

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set< vector<int> >st;
        for(int i=0;i<n;i++){
            set<int>HashSet;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(HashSet.find(third) != HashSet.end()){
                    vector<int>temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                HashSet.insert(nums[j]);
            }
        }
        vector< vector<int> > ans (st.begin(),st.end());
        return ans;
    }
};




// brute force TC: O(n^3)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set< vector<int> >st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);}
                }
            }
        }
        vector< vector<int> > ans (st.begin(),st.end());
        return ans;
    }
};
