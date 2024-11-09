//better but space complexity O(n) + O(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n);
        vector<int> col(m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(matrix[i][j]==0){
                    row[i]=1; 
                    col[j]=1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};





///brute force complexity - (n*m) * (n+m) + (n*m)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    int p = i;
                    int q = j;
                    for(int k=0;k<m;k++){
                        if(matrix[p][k]!=0)matrix[p][k]=-10021;
                    }
                    for(int k=0;k<n;k++){
                        if(matrix[k][q]!=0)matrix[k][q]=-10021;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-10021){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
