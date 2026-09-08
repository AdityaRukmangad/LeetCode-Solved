class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<pair<int,int> , int>> q;
        int time = 0;
        
        for(int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 2 ){
                    q.push({{i,j},time});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop(); 
            time = t;
            vector<int> drow ={-1 , 0 , 1 , 0 };
            vector<int> dcol = { 0 ,1, 0 , -1 };
            
            for(int i =0; i<4 ;i++){
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    q.push({{nr,nc},t+1});
                    
                }
            }

        }
                for(int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 1 ){
                    return -1;
                }
            }
        }
        return time ;
    }
};