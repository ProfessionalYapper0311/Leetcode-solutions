//solution is to return the sum of abs differnce between x and the mid
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mid;
        int n = nums.size();
        std::sort(begin(nums), end(nums)); 
        int moves = 0;
        
        for(int i =0; i<n; i++){
            if(n%2 != 0){
                mid = nums[n/2]; //odd case
            }
            else{
                mid = ( nums[(n-1)/2] + nums[n/2] ) / 2.0; //even case
            }
            moves += abs(nums[i]-mid);
        }
        return moves;
    }
};