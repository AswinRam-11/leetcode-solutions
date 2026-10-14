class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            if(a>0 && a<=nums.size()){
                int temp = a;
                nums[i]=nums[a-1];
                nums[a-1]=temp;
                if(nums[i]!=nums[a-1]){
                    i--;
                }
            }
        }
        for(int i=1; i<nums.size()+1; i++){
            if(nums[i-1]!=i) return i;
        }
        return nums.size()+1;
    }
};