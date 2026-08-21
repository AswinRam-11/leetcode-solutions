class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev0=0,prev1=0,prevprev0=0,prevprev1=0;
        int pres0=0,pres1=0;
        for(int i=2; i<n+1; i++){
            pres0= cost[i-1]+min(prev1,prev0);
            pres1 = cost[i-2]+ min(prevprev1,prevprev0);
            prevprev1=prev1;
            prevprev0=prev0;
            prev1=pres1;
            prev0=pres0;
        }
        return min(pres0,pres1);
    }
};