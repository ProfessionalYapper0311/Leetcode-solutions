class Solution {
public:

    int memo[1001]; //constraint are size of 1000

    int solve(int idx, vector<int>&cost){
        if(idx>= cost.size()){
            return 0;
        } //base case, that is out of bounds
        
        if(memo[idx] != -1){
            return memo[idx];
        }

        //from the given step, two options
        int a = cost[idx] + solve(idx+1, cost);
        int b = cost[idx] + solve(idx+2, cost);

        return memo[idx] = min(a, b); //that is starting point is 0 or 1 and memoize, changing var
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //idx 0 or idx 1 is tthe starting
        int n = cost.size();

        memset(memo, -1, sizeof(memo)); //arranme, val, sizeof
        //after idx 0 and idx 1 you can either take i+1 steps or i+2 steps
        return min(solve(0, cost), solve(1, cost));
    }
};