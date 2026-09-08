class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int , int >> q;
        int count =0;
        for(int i =0 ; i< m; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    grid[i][j] ='2';
                    count ++;
                    q.push({i,j});
                }
                while(!q.empty()){

                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    vector<int> dr ={-1 , 0 , 1 ,0 };
                    vector<int> dc = { 0,1,0,-1};

                    for(int k =0 ; k < 4;k++){
                        int nr = row+dr[k];
                        int nc = col+dc[k];

                        if(nr >=0 && nc >= 0 && nr <m && nc <n && grid[nr][nc] == '1'){
                            q.push({nr,nc});
                            grid[nr][nc] ='2';

                        }

                    }


                }
            }
        }
        return count;

    }
};