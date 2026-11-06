class Solution {
public:

    void solve(vector<int>& temp, vector<int>& nums, int idx, vector<vector<int>>&result){
        result.push_back(temp);//check not needed because all states are valid state, simply push
        //i>=n is handled by for loop itself, it will never go past beyond n

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i-1] == nums[i]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(temp, nums, i+1, result);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        //handling duplicates, sort + filter
        std::sort(begin(nums), end(nums));
        solve(temp, nums, 0, result);

        return result;
    }
};