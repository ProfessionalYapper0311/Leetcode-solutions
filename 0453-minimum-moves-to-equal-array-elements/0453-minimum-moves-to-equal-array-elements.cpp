class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int min_ele = *min_element(begin(nums), end(nums));
        for(int i=0; i<nums.size(); i++){
            count += nums[i] - min_ele; 
        }
        return count;
    }
};