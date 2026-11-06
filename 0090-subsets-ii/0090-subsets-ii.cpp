class Solution {
public:
vector<vector<int>>result;
    void solve(vector<int>& temp, vector<int>& nums, int idx){
        result.push_back(temp);//check not needed because 

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i-1] == nums[i]){
                continue;
            }
            temp.push_back(nums[i]);
            solve(temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        //handling duplicates, sort + filter
        std::sort(begin(nums), end(nums));
        solve(temp, nums, 0);

        return result;
    }
};