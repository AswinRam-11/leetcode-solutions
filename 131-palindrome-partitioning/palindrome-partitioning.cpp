class Solution {
public:
    bool palindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void findAns(string s, vector<vector<string>>& ans, vector<string>& pres, int i, int j){
        if(j==s.size()){
            if(palindrome(s,i,j)){
                ans.push_back(pres);
            }
            return;
        }
        while(j<s.size()){
            if(palindrome(s,i,j)){
                pres.push_back(s.substr(i,j-i+1));
                findAns(s,ans,pres,j+1,j+1);
                pres.pop_back();
            }
            j++;
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int i=0, j=0;
        vector<string> pres;
        findAns( s, ans, pres, i,j);
        return ans;
    }
};