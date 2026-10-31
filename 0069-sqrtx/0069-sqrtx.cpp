class Solution {
public:
    int mySqrt(int x) {
        int left = 0; int right = x;
        int ans = 0;
        while(left <= right){
            //binary search
            int mid = left + (right - left) / 2; // or lo + hi //2
            if((long long) mid * mid <= x){ //avoid overflow
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};