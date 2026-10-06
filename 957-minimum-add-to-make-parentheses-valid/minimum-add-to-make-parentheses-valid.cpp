class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char> st;
        int n = s.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push('(');
            }
            else if(!st.empty()){
                st.pop();
            }else{
                count++;
            }
        }
        count+=st.size();
        return count;
    }
};