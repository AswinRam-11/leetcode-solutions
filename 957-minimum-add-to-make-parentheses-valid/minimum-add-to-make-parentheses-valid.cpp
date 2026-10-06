class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int count=0;
        int paran=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                paran++;
            }
            else if(paran!=0){
                paran--;
            }else{
                count++;
            }
        }
        count+=paran;
        return count;
    }
};