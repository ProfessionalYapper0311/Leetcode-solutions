class Solution {
public:
vector<int>memo;
    int solve(int i, int n, vector<int>& costs){
        if(i == n) return 0; //reched the final step
        
        if(memo[i] != -1){ //if not -1
            return memo[i];
        }

        int cost = INT_MAX; 

        int j = i+1; //possible step 1
        if(j<=n){
            cost = min(cost, costs[j-1] + ((j-i)*(j-i)) + solve(j, n, costs));
        }
        j = i+2; //possible step 2
        if(j<=n){
            cost = min(cost, costs[j-1] + ((j-i)*(j-i)) + solve(j, n, costs));
        }
        j = i+3; //possible step 3
        if(j<=n){
            cost = min(cost, costs[j-1] + ((j-i)*(j-i)) + solve(j, n, costs));
        }

        return memo[i] = cost; //meomize the cost
    }
    int climbStairs(int n, vector<int>& costs) {
        memo.assign(n+1, -1); //initialize -1 to memo vector
        return solve(0, n, costs); //idx, n, cost vector
    }
};