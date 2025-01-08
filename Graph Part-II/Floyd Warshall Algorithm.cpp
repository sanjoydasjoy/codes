question link:
https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0;i<n; i++) {
            for(int j = 0;j<n; j++) {
                if(mat[i][j] == -1) {
                    mat[i][j] = 1e9;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        for(int i = 0;i<n; i++) {
            for(int j = 0;j<n; j++) {
                if(mat[i][j] == 1e9) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};
