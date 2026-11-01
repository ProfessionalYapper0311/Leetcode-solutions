class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> maxHeap(nums.begin(), nums.end()); //O(n) heapify
        while(--k){ //k-- will pop one more, instead do --k, that's k-1 times   
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};