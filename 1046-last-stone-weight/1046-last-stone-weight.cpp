class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxh(stones.begin(),stones.end()); //o(n) max heapify
        //while the size of pq is greater keeping poping and pusshing back smashed stone
        while(maxh.size() > 1){
            int y = maxh.top(); maxh.pop(); //first stone
            int x = maxh.top(); maxh.pop(); //second stone

            if(y!=x){                       //unequal stone, so smash, equal then do nothing cause y-0 = y
                maxh.push(y-x);
            }
        }
        //eg- [2,2] both destroyed, nothing pushed, empty heap
        return maxh.empty() ? 0 : maxh.top(); 
    }
};