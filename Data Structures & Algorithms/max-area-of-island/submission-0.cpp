class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int& temp, int i, int j, int row, int col){
        //base cond
        if(i<0 || j<0 || i>=row || j>=col){
            return;
        }
        if(vis[i][j]){
            return;
        }
        if(grid[i][j]!=1){
            return;
        }

        vis[i][j] = true;
        temp++;

        //check for all the neighbours
        dfs(grid,vis,temp,i-1,j,row,col);
        dfs(grid,vis,temp,i+1,j,row,col);
        dfs(grid,vis,temp,i,j-1,row,col);
        dfs(grid,vis,temp,i,j+1,row,col);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int temp = 0;
                    dfs(grid,vis,temp, i, j, n, m);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};