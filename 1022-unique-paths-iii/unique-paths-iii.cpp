class Solution {
public:
    int findAns(vector<vector<int>>& grid,int i, int j, int notVisited){
        int arrx[] = {1,-1,0,0};
        int arry[] = {0,0,1,-1};
        int ans=0;
        for(int k=0; k<4; k++){
            int x=i+arrx[k];
            int y=j+arry[k];
            if(x<grid.size() && x>=0 && y<grid[0].size() && y>=0 && (grid[x][y]==0 || grid[x][y]==2)){
                if (grid[x][y]==0){
                    grid[x][y]=-1;
                    notVisited--;
                    cout<<notVisited<<endl;
                    ans+=findAns(grid,x,y,notVisited);
                    grid[x][y]=0;
                    notVisited++;
                }else if (grid[x][y]==2 && notVisited==0){
                    return 1;
                }
                
            }
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y;
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0;j<grid[i].size(); j++){
                if(grid[i][j]==1){
                    x=i; y=j;
                }
                if(grid[i][j]==0) count++;
            }
        }
        return findAns(grid,x,y,count);
    }
};