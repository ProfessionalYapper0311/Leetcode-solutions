class Solution {
public:
    vector<vector<int>> result; //store the result
    unordered_set<int>st; //store the used elements

    int n;

    void solve(vector<int>&temp, vector<int>& nums){ 
        if(temp.size() == n){ // no more elements/ base case
            result.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){ //no index pushed to function
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums); //backtrack

                temp.pop_back();
                st.erase(nums[i]);
            } 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>temp; //auxillary space

        solve(temp, nums);

        return result;
    }
};