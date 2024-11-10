// two pointer solution TC: O(n) for vector pair , O(nlogn) for sort, O(n) for two pointer 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;

        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());

        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int sum = v[left].first + v[right].first;

            if(sum<target)left++;
            else if(sum>target)right--;
            else return {v[left].second, v[right].second};
        }
        return {};

    }
};


// better using map TC: O(nlogn) since its ordered map..O(N) if unordered_map in best and avg but O(n^2) for worst SC: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            int b = target - nums[i];

            if(mp.find(b) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[b]);
                return ans;
            }
            else mp[a] = i;
        }
        return ans;
    }
};



//brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            for(int j = 0;j<nums.size();j++){
                if(i!=j && (nums[i] + nums[j] == target)){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};
