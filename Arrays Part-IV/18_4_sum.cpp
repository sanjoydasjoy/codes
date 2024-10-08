// optimal solution

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j != i+1 && nums[j]==nums[j-1])continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];

                    if(sum>target)l--;
                    else if(sum<target)k++;
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
                    }
                }
            }
        }
        return ans;
    }
};



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

//Inserting into a set takes O(log m) where m is the size of the set. 
//If the set contains at most O(n⁴) elements (the worst case, based on the four nested loops),
//the time complexity for an insertion would be O(log (n⁴)).
//so set insertion could take up to O(log n⁴) = O(4 log n) = O(log n).
//This is relatively insignificant compared to the O(n⁴) iteration count, 
//so it doesn't change the overall time complexity.


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
