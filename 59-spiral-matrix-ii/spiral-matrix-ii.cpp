class Solution {
public:
    void generateMatrix(vector<vector<int>>& arr, int val,int n,int start){
        if(start>n/2) return;
        int i=start;
        int j=start;
        for(j; j<n-start; j++){
            arr[i][j]=val;
            val++;
        }
        j--;
        i++;
        for(i;i<n-start;i++){
            arr[i][j]=val;
            val++;
        }
        i--;
        j--;
        for(j; j>=start; j--){
            arr[i][j]=val;
            val++;
        }
        j++;
        i--;
        for(i; i>start; i--){
            arr[i][j]=val;
            val++;
        }
        generateMatrix(arr,val,n,start+1);
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int layer=(n+1)/2;
        int val=1;
        int start=0;
        generateMatrix(ans,val,n,start);
        return ans;
    }
};