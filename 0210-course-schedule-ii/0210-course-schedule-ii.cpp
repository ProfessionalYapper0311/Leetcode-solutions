class Solution {
public:
    vector<int> KahnsAlgocheck(unordered_map<int, vector<int>>&adj, int nc, vector<int>&indegree){
        queue<int>que;
        int count = 0;

        vector<int>result; 

        for(int i=0; i<nc; i++){
            if(indegree[i] == 0){
                result.push_back(i);
                count++; 
                que.push(i); //indegree is 0, push to queue
            }
        }

        while(!que.empty()){
            int u = que.front(); que.pop();
            for(int&v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    result.push_back(v);
                    count++;
                    que.push(v);
                }
            }
        }
        return (nc == count) ? result : vector<int>{}; //empty array
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses, 0);

        //make graph and populate the indegree vector
        for(auto&vec : prerequisites){
            int a = vec[0];
            int b = vec[1];

            //b--> a and ---> a
            adj[b].push_back(a);
            indegree[a]++;
        }

        return KahnsAlgocheck(adj, numCourses, indegree);
    }
};