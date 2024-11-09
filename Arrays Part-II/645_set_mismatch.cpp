class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        vector<int> well;
        int p[] = {1};
        int f = 1, sum = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)sum += nums[i];
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                well.push_back(nums[i]);
                sum -= nums[i];
            }
        }
        
        int x = n * (n + 1) ;
        x/= 2;
        well.push_back(x-sum);

        return well;
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        vector<int> well;
        
        int n = nums.size();
        vector<int> hash(n+1, 0);

        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(hash[i]==2)well.push_back(i);
            
        }
        for(int i=1;i<=n;i++){
            if(hash[i]==0)well.push_back(i);
        }
        

        return well;
    }
};
