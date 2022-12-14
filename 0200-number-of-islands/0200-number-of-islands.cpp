class Solution {
    private:
    //usinf dfs
    void dfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid, int delrow[], int delcol[])
    {
        
        vis[row][col]=1;
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                dfs(nrow, ncol, n, m, vis, grid, delrow, delcol);
            }
        }
    }
    //using bfs
//     void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid, int delrow[], int delcol[]){
        
//         vis[row][col]=1;
//         queue<pair<int, int>>q;
//         q.push({row, col});
        
//         int n=grid.size();
//         int m=grid[0].size();
        
//         while(!q.empty())
//         {
//             int row=q.front().first;
//             int col=q.front().second;
//             q.pop();
            
//             for(int i=0;i<4;i++)
//             {
//                 int nrow = row + delrow[i];
//                 int ncol = col + delcol[i];
                
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
//                 {
//                     vis[nrow][ncol]=1;
//                     q.push({nrow, ncol});
//                 }
//             }
//         }
//     }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));   //visited matrix
        int cnt=0;
        
        int delrow[]={-1, 0, 1, 0}; //checking for all 4 directions whether it has 0 or 1
        int delcol[]={0, 1, 0, -1};
    
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<m;col++)
            {
                if(!vis[row][col] && grid[row][col]=='1')
                {
                    cnt++;
                    dfs(row, col, n, m, vis, grid, delrow, delcol);
                }
            }
        }
        return cnt;
    }
};