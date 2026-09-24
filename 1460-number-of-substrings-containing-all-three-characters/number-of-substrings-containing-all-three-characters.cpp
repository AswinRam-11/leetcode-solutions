class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        int n = s.size();
        vector<int> count(3,0);
        int ans=0;
        count[s[r]-'a']++;
        while(l<n && r<n){
            if(count[0] && count[1] && count[2]){
                ans+=n-r;
                count[s[l]-'a']--;
                l++;
            }else{
                r++;
                if(r==n) continue;
                count[s[r]-'a']++;
            }
        }
        
        return ans;
    }
};