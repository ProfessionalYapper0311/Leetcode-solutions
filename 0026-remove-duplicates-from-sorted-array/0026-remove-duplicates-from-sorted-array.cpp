class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1; //1 indexing
        for(int r = 1; r< nums.size(); r++){
            if(nums[r-1] != nums[r]){
                nums[left] = nums[r];
                left++;
            }
        }
        return left;
    }
};