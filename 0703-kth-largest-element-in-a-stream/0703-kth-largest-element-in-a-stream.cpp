class KthLargest {
public:
priority_queue<int, vector<int>, greater<int>> minh; //min heap with n elements from nums
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k; //intialize k as constructor parameter
        for(int num : nums){
            minh.push(num);
            if(minh.size() > k){
                minh.pop();
            }
        }
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size() > k){
            minh.pop();
        }
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

 //tc - n elements, size of pq is k, delete is log k so O(n.log.k)
 //add op- M times add called, also M times popped so logK so O(M. log(k))
 //sc - O(n) or O(k) since heap is size of k