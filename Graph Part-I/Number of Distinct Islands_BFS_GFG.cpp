question link: 
https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

class Solution {
  private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

                for(int i=0;i<8;i++){
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                    && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};
