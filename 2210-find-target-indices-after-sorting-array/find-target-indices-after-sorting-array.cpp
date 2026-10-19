class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int start=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<target){
                start++;
            }
            else if (nums[i]==target){
                count++;
            }
        }
        vector<int> ans;
        for(int i=0; i<count; i++){
            ans.push_back(start+i);
        }
        return ans;
    }
};