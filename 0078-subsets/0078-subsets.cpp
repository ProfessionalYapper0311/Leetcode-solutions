class Solution {
public:
vector<vector<int>>result; //globally push temp in here

    void backtrack(vector<int>&temp, int i, vector<int>& nums){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }
        //main backtracking algo
        temp.push_back(nums[i]); //choose
        backtrack(temp, i+1, nums); //explore
        temp.pop_back(); //not choose
        backtrack(temp, i+1, nums); //explore

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp; //auxillary space

        backtrack(temp, 0, nums); //call the backtracking function

        return result;
    }
};