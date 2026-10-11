class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=0;
        int maxi=0;
        for(int i=1; i<n; i++){
            if(nums[i]>nums[maxi]){
                maxi=i;
            }
            if(nums[i]<nums[mini]){
                mini=i;
            }
        }
        int left1st, left2nd, right1st,right2nd;
        left1st=min(mini,maxi)+1;
        left2nd=max(mini,maxi)+1;
        right1st = n-max(mini,maxi);
        right2nd = n-min(mini,maxi);
        
        //cout<<left1st<<" "<<left2nd<<" "<<right1st<<" "<<right2nd<<endl;
        int ans = min(left1st+right1st,min(left2nd,right2nd));
        return ans;
    }
};