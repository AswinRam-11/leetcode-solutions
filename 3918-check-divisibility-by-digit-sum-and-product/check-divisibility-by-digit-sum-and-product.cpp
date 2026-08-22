class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int prod=1, dig=0;
        while(n>0){
            int pres = n%10;
            n/=10;
            prod*=pres;
            dig+=pres;
        }
        return !(num%(prod+dig));
    }
};