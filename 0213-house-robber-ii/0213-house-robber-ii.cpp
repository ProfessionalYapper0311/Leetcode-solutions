class Solution {
public:
    int maxRobHouse(vector<int>& nums, int start, int end){
        int len = end - start + 1; //subarray size either 0 -> n-2 or 1 -> n-1, not full array size
        if(len == 1) return nums[start]; //base case

        int best[101];

        best[0] = nums[start]; //first index of nums
        best[1] = max(nums[start], nums[start + 1]); //max of both first and second index

        for(int i = 2; i<len; i++){ //0, 1 found, form 2 to len
            best[i] = max(best[i-1], nums[start + i] + best[i-2]); //since start = 1 also
            /*When i = 2, you're looking at the 3rd house in that slice (nums[3]), not nums[2]—which you already accounted for in best[1]. Using nums[i] would double-count nums[2] and completely miss nums[n - 1]*/
        }
        return best[len-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0]; //base case

        //main logic
        // Case 1: Exclude last house [0 ... n-2] if first house
        // Case 2: Exclude first house [1 ... n-1]   if last house
        return max(maxRobHouse(nums, 0, n-2), maxRobHouse(nums, 1, n-1)); //case 1 and case 2, max of both
    }
};

//last time -> best, best[i-1] or nums[i] + best[i-2], and then best[n-1], skip or steal that is
//diff is that house's are in circle, therefore (1, 2, 3, 4 -> 1) like we can't steal 1 and 2, similrly 1 and 4 also