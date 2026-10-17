class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string a(n,'.');
        string b(n-1,'#');
        b+=".";
        vector<string> ans(m,b);
        ans[0]=a;
        return ans;
    }
};