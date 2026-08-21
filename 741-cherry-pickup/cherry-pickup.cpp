class Solution {
public:
    int f(int i1 ,int j1, int i2 ,int j2,vector<vector<int>>&grid,vector<vector<vector<vector<int>>>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i1>=m || j1>=n || grid[i1][j1]==-1 || i2>=m || j2>=n || grid[i2][j2]==-1) return -1e9;
        if(i1==m-1 && j1==n-1) return grid[i1][j1];

        if(dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

        int ans = grid[i1][j1]+grid[i2][j2];
        
        if(i1==i2&&j1==j2) ans-=grid[i1][j1];

        int rr =f(i1,j1+1,i2,j2+1,grid,dp);
        int rd =f(i1,j1+1,i2+1,j2,grid,dp);
        int dr =f(i1+1,j1,i2,j2+1,grid,dp);
        int dd =f(i1+1,j1,i2+1,j2,grid,dp);

        return dp[i1][j1][i2][j2]= ans + max(max(rr,rd),max(dr,dd));
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans=f(0,0,0,0,grid,dp);
        return max(0,ans);
    }
};