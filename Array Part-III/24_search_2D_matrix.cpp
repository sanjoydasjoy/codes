// lil optimized using binary search built in function TC: O(n) + O(logn)

#include <bits/stdc++.h>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] <= target && matrix[i][m - 1] >= target) {
                if (binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                    return true;
                }
            }
        }
        return false;
    }
};






// brute force but a lil optimized TC: O(2n)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size();
        int m =  matrix[0].size();
        int ind = -1;
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && matrix[i][m-1]>=target){ind = i;break;}
        }
        if(ind==-1)return false;
        for(int j=0;j<m;j++){
            if(matrix[ind][j]==target)return true;
        }
        return false;
        
    }
};



// brute force TC: O(N*M) SC: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size();
        int m =  matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target)return true;
            }
        }
        return false;
        
    }
};
