class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int x: nums){
            minHeap.push(x);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int, vector<int>, less<int>> maxHeap(nums.begin(), nums.end()); //O(n) heapify
//        while(--k){ //k-- will pop one more, instead do --k, that's k-1 times   
//            maxHeap.pop();
//       }
//        return maxHeap.top();
//   }
//};