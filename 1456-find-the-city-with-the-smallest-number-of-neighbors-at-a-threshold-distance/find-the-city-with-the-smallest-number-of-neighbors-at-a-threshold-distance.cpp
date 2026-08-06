class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e5));
        for(int i=0; i<edges.size(); i++){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) matrix[i][j]=0;
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        vector<int> maximum(n,0);
        int ans=n-1;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(matrix[i][j]<=distanceThreshold){
                    maximum[i]++;
                }
            }
            if(maximum[ans]>maximum[i]) ans=i;
        }
        
        return ans;
    }
};