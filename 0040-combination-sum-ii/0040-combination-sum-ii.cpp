class Solution {
public:
vector<vector<int>>result;
    void solve(vector<int>& candidates, vector<int>&temp, int target, int idx){
        if(target < 0 || idx>candidates.size()) return; //dead end

        if(target == 0){ //result found
            result.push_back(temp);
            return;
        }


        for(int i=idx; i<candidates.size(); i++){ 
    //we start from idx, and only if i>idx, or for eg, 1>0 then only then check i-1 == 1, or stack overflow
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;//same element
            }
            
            temp.push_back(candidates[i]); //take
            solve(candidates, temp, target - candidates[i], i + 1); //explore next now, i+1
            temp.pop_back(); //do not taek, no need for another explore cause for loop
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        std:sort(begin(candidates), end(candidates));
        solve(candidates, temp, target, 0);
        return result;
    }
};