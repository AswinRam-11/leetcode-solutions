class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string a(n,'.');
        string b(n-1,'#');
        b+=".";
        ans.push_back(a);
        for(int i=1; i<m; i++){
            ans.push_back(b);
        }
        return ans;
    }
};