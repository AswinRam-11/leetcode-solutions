class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int count=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                count++;
            }else if(s[i]==')' && i<n-1 && s[i+1]==')'){
                if(count==0){
                    //cout<<i<<endl;
                    ans+=1;
                }
                else{
                    count--;
                }
                i++;
            }else{
                if(count==0){
                    //cout<<i<<endl;
                    ans+=1;
                }
                else{
                    count--;
                }
                
                    ans+=1;
            }
        }
        ans+=2*count;
        return ans;
    }
};