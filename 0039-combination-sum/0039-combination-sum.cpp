class Solution {
public:
vector<vector<int>> result;
    void solve(vector<int>& temp, vector<int>& candidates, int target, int i){
        if(target == 0){
            result.push_back(temp);
            return;
        } //amswer found

        if(target < 0 || i>= candidates.size()){
            return;
        } //way beyong answer, dead end

        temp.push_back(candidates[i]); //take the number
        solve(temp, candidates, target - candidates[i], i); //explore
        temp.pop_back(); //do not take that element
        solve(temp, candidates, target, i+1);

    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp; //auxi space
        solve(temp, candidates, target, 0);
        return result;
    }
};