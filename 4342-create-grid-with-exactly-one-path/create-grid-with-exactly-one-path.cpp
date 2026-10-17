class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string a(n,'.');
        string b(n,'#');
        b[n-1]='.';
        vector<string> ans(m,b);
        ans[0]=a;
        return ans;
    }
};