class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=2;
        int count=1;
        if(nums.size()==1) return 1;
        for(int i=1; i<nums.size()-1; i++){
            while(j<nums.size() && nums[i]==nums[i-1] && nums[j]==nums[i]){
                j++;
            }
            if(j>=nums.size()) break;
            nums[i+1]=nums[j];
            j++;
            count++;
        }
        return count+1;

    }
};