class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int pres, vector<int>& group){
        int presCol= group[pres];
        for(int i=0; i<graph[pres].size(); i++){
            int check=graph[pres][i];
            if(presCol==group[check]){
                return false;
            }
            else if(group[check]==-1){
                group[check]=(presCol)?0:1;
                if(!dfs(graph,check,group)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> group(n,-1);
        for(int i=0; i<n; i++){
            if(group[i]==-1){
                group[i]=0;
                if (!dfs(graph,i,group)){
                    return false;
                }
            }
        }
        return true;
    
    }
};