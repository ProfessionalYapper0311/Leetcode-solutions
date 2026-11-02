class MedianFinder {
public:
    priority_queue<int> left_pq; //left maxh alwasy larger
    priority_queue<int, vector<int>, greater<int>> right_pq;  //right smaller min heap

    MedianFinder() {
    }
    
    void addNum(int num) {
        //insert left heap smaller num, right heap greater num[1, 2, 3 || 4, 5, 6]
        if(left_pq.empty() || num < left_pq.top()){
            left_pq.push(num);
        }
        else{
            right_pq.push(num);
        } 

        //case1 differnce in size is greater than 1, left pq is greater
        if(abs((int)left_pq.size() - (int)right_pq.size()) > 1){
            right_pq.push(left_pq.top());
            left_pq.pop();
        }
        //case 2, right pq is greater than left
        else if(right_pq.size() > left_pq.size()){
            left_pq.push(right_pq.top());
            right_pq.pop();
        }
    }
    
    double findMedian() {
        //same size, then even
        if(left_pq.size() == right_pq.size()){
            return (double) (left_pq.top() + right_pq.top()) / 2.0;
        }
        //left > right, odd
        return (double) left_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */