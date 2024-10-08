// Combinatorial approach to calculate unique paths in an m x n grid
// Time complexity: O(n-1) or O(m-1) for the loop
// Space complexity: O(1) as no extra space is used



class Solution {
public:

    int uniquePaths(int m, int n) {

        double x = m+n-2,y = m-1,ans = 1;

        for(int i=1;i<=y;i++){
            ans *= x;
            ans /= i;
            x-=1;
        }
        return (int)(ans + 0.5);

    }
};



// dynamic programming 

class Solution {
public:
    int recursion(int m, int n, int i, int j,vector<vector<int>>&dp) {
        if ((i==m-1) && (j==n-1)) return 1;
        
        if( (i>m-1) || (j>n-1)) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        
        else return dp[i][j] = recursion(m,n,i,j+1,dp) + recursion(m,n,i+1,j,dp);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m,vector<int>(n,-1));
        int x = recursion(m, n, 0, 0, dp);

        return x;
    }
};




// recursion TC: exponential time complexity due to the recursion tree/ overlapping subproblems specifically O(2^(m+n))

class Solution {
public:
    int recursion(int m, int n, int i, int j) {
        if ((i==m-1) && (j==n-1)) return 1;
        
        if( (i>m-1) || (j>n-1)) return 0;
        
        return recursion(m,n,i,j+1) + recursion(m,n,i+1,j);
    }
    int uniquePaths(int m, int n) {
        
        int x = recursion(m, n, 0, 0);

        return x;
    }
};
