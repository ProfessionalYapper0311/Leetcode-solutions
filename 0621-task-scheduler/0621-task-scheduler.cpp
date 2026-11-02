class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //set the data structures neccessary, vector - map, priority queue - for heap, time var for output

        vector<int>map(26, 0); //freq counter arr 

        for(char &ch: tasks){
            map[ch - 'A']++; //populate the arr freq counter [A - 3, B - 3, C - .... Z - 0]
        }

        int time = 0;
        priority_queue<int> pq; //maxheap by default

        for(int i=0; i<26; i++){
            if(map[i] > 0) pq.push(map[i]); //populate the maxheap [3, 3]
        }

        //main logic
        while(!pq.empty()){
            vector<int> temp;
            //n+1 tasks
            for(int i = 0; i<n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top(); //[3, 3]
                    pq.pop();
                    freq--;
                    temp.push_back(freq); //[2, 2]
                }
            }
            for(int &f : temp){ //from temp back to pq so [2,2] pushed to pq
                if(f > 0){
                    pq.push(f);
                }
            }
        //calculate the total time
        if(pq.empty()){
            time += temp.size();
        }
        else{
            time += n+1;
        }    
        }
        return time;
    }
};