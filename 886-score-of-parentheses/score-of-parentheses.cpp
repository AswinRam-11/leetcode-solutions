class Solution {
public:
    int findScore(int & i,string s){
        if(s[i]==')'){
            return 1;
        }
        int score=0;
        int pres=0;
        for(; i<s.size(); i++){
            if(s[i]=='('){
                i++;
                pres=findScore(i,s);
            }
            else{
                break;
            }
            score+=pres;
        }
        return 2*score;
    }
    int scoreOfParentheses(string s) {
        int i=0;
        int score = findScore(i, s);
        return score/2;
    }
};