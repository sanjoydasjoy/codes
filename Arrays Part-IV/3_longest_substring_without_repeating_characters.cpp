//brute force TC: O(n²) SC:O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int mx=0;
        for(int i=0;i<n;i++){
            unordered_set<char>st;
            int cnt=0;
            for(int j=i;j<n;j++){
                if(st.find(s[j]) != st.end()){
                    break;
                }
                st.insert(s[j]);
                mx=max(mx,j-i+1);
            }
        }
        return mx;
    }
};
// similar but without using set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int mx=0;
        for(int i=0;i<n;i++){
            vector<int> freq(256, 0);
            for(int j=i;j<n;j++){
                if(freq[s[j]]!=0){
                    break;
                }
                freq[s[j]]++;
                mx=max(mx,j-i+1);
            }
        }
        return mx;
    }
};
