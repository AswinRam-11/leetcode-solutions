class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int prev=-1;
        int n=s.size();
        vector<int> ans(s.size());
        for(int i=0; i<n; i++){
            if(s[i]==c){
                prev=i;
                ans[i]=0;
            }
            else if(prev==-1){
                ans[i]=INT_MAX;
            }
            else{
                ans[i]=i-prev;
            }
        }
        prev=-1;
        for(int i=n-1; i>=0; i--){
            if(s[i]==c){
                prev=i;
                ans[i]=0;
            }
            else if(prev==-1){
                continue;
            }
            else{
                ans[i]=min(prev-i,ans[i]);
            }
        }
        return ans;
    }
};