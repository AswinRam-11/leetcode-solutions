class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        if (end==0) return 0;
        if (nums[0]>nums[1]) return 0;
        if (nums[end]>nums[end-1]) return end;
        start=1;
        end=end-1;
        while(end>=start){
            int mid = (end-start)/2+start;
            if( nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid]>nums[mid-1]){
                start = mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};