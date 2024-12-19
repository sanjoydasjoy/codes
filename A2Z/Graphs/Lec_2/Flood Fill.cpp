class Solution {
private: 
void dfs(vector<vector<int>>& ans,vector<vector<int>>& image, int sr, int sc, int newColor, int initialColor, int deltaRow[], int deltaColumn[]){
    ans[sr][sc] = newColor;
    for(int i=0;i<4;i++){
        int currRow = sr + deltaRow[i];
        int currCol = sc + deltaColumn[i];
        int n = image.size();
        int m = image[0].size();
        if(currRow>=0 && currRow<n && currCol>=0 && currCol<m && image[currRow][currCol]==initialColor 
            && ans[currRow][currCol] != newColor){
                dfs(ans, image, currRow, currCol, newColor, initialColor, deltaRow, deltaColumn);
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        vector<vector<int>>ans = image;
        int deltaRow[] = {-1,0,+1,0};
        int deltaColumn[] = {0,+1,0,-1};
        dfs(ans, image, sr, sc, color, initialColor, deltaRow, deltaColumn);

        return ans;

    }
};
