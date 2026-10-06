class Solution {
public:
    int minRotations(string s) {
        char pres='0';
        int ans=0;
        for(char& ch: s){
            ans+=min((10+ch-pres)%10,(10+pres-ch)%10);
            pres=ch;
        }
        return ans;
    }
};