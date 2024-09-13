// my solution TC O(n*n) SC O(n*n)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> copy(n, vector<int>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                copy[i][j] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = copy[n-j-1][i];
            }
        }
        
    }
};

// constant space complexity 

// intution : transpose the matrix and then reverse each row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};






//




#include <bits/stdc++.h>
using namespace std;

void tranpose(vector<vector<int>>mat, int n){
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			swap(mat[i][j], mat[j][i]);
		}
	}
	for(int i=0;i<n;i++){
			reverse(mat[i].begin(),mat[i].end());
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{

	int n;cin>>n
	vector<vector<int>>mat(n,vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}

	tranpose(mat,n);
	
}



