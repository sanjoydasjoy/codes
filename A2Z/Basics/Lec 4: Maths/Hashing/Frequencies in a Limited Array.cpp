question link:
https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

class Solution {
  public:
    
    vector<int> frequencyCount(vector<int>& arr) {
        map<int,int>mp;
        int n = arr.size();
        vector<int>ans;
        for(auto i:arr)
            mp[i]++;
        
        for(int i=0;i<arr.size();i++){
            ans.push_back(mp[i+1]);
        }
        return ans;
    }
};


/*
Summary:
If You Predefine the Vector Size:
When you initialize a vector with a predefined size (e.g., vector<int> ans(n, 0)), the vector already contains n elements.
In this case:
You should NOT use push_back , because push_back adds new elements to the end of the vector, increasing its size beyond n.
Instead, use direct assignment (ans[i] = ...) to update the existing elements.
If You Don't Predefine the Vector Size:
If you initialize an empty vector (e.g., vector<int> ans;), it starts with size 0.
In this case:
You CAN use push_back to add elements one by one.
However, you cannot directly assign values to indices that don't exist yet (e.g., ans[5] = 10 would cause an error if the vector has fewer than 6 elements).

  */
