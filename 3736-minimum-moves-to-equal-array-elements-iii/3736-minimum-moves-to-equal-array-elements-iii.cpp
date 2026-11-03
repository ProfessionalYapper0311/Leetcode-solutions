class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele = *max_element(begin(nums), end(nums));
        int min_move = 0;
        for(int x : nums){
            min_move += abs(x - max_ele);
        }
        return min_move; 
    }
};